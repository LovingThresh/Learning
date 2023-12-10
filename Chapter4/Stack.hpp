//
// Created by liuye on 2023/11/27.
//

#ifndef STACK_H
#define STACK_H
#include <string>
#include <vector>
using namespace std;

namespace regular{
class Stack {

public:
    ~Stack() = default;
    Stack();
    explicit Stack(int len);

    [[nodiscard]] bool pop(string &elem);
    [[nodiscard]] bool push(const string &elem);
    [[nodiscard]] bool peek(string &elem) const;

    [[nodiscard]] bool empty() const;
    [[nodiscard]] bool full() const;

    [[nodiscard]] int size() const { return static_cast<int>(_stack.size());}
private:
    vector<string> _stack;
};
}

namespace stack_templated{
    template <class Type, int Max>
    class Stack_Temlated {
    private:
        Type items[Max];
        int top;
    public:
        Stack_Temlated(){top=0;}
        [[nodiscard]] bool isempty() const {return top==0;}
        [[nodiscard]] bool isfull() const {return top==Max;}
        bool push(const Type &item);
        bool pop(Type &item);
};
}

#endif //STACK_H
