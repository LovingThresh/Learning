#ifndef QUEUE_H
#define QUEUE_H
// #include <random>

class Customer
{
private:
    long arrive; // arrival time for customer
    int processtime; // processing time for customer

public:
    Customer():arrive(0), processtime(0){}
    void set(long when);
    [[nodiscard]] long when() const { return arrive; }
    [[nodiscard]] int ptime() const { return processtime; }
};

template <typename Item>
class Queue {
private:
    enum {Q_SIZE = 10};
    struct Node {
        Item item_element;
        Node* next; // 指向下一个节点的指针
    };
    // front *指针 表示队列的首个元素
    // rear *指针 表示队列的末尾元素
    Node *front;
    Node *rear;
    int items;
    const int q_size;
public:
    explicit Queue(const int qs=Q_SIZE) :q_size(qs)
    {
        front = rear = nullptr;
        items = 0;
    };
    ~Queue();
    [[nodiscard]] bool isfull() const;
    [[nodiscard]] bool isempty() const;
    [[nodiscard]] int queuecount() const;
    bool enqueue(const Item &item); // 链表 末尾添加
    bool dequeue(Item &item); // 链表 先进先出
};
template<typename Item>
Queue<Item>::~Queue() {
    while (front != nullptr) {
        const Node* temp = front;
        front = front->next;
        delete temp;
    }
};

template<typename Item>
bool Queue<Item>::isempty() const{
    return items == 0;
}

template<typename Item>
bool Queue<Item>::isfull() const{
    return items == q_size;
}

template<typename Item>
int Queue<Item>::queuecount() const{
    return items;
}

template<typename Item>
bool Queue<Item>::enqueue(const Item &item) {
    if (items == q_size) // if (isfull())
        return false;
    Node* add = new Node; // Create a new node
    add->item_element = item; // Assign the item to the new node
    add->next = nullptr; // The new node does not have a next node yet
    items++; // Increase the number of items in the queue
    if (front==nullptr)
        front = add; // If the queue was empty, the new node is now the front of the queue
    else
        rear->next = add; // If the queue was not empty, the new node is added after the current rear
    rear = add; // The new node is now the rear of the queue
    return true;
}

// dequeue根据链表的先进先出的原则，那么dequeue就是要退出队列的第一个元素
template<typename Item>
bool Queue<Item>::dequeue(Item &item) {
    if (front == nullptr)
        return false;
    item = front->item_element; // Copy the item from the node
    items--; // Decrease the number of items in the queue
    const Node *temp = front;
    front = front->next; // Set the front to the next node
    delete temp; // Delete the previous front node
    if (items == 0)
        rear = nullptr;
    return true;
}
#endif //QUEUE_H
