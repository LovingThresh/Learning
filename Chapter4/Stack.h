//
// Created by liuye on 2023/11/27.
//

#ifndef STACK_H
#define STACK_H
#include <string>
#include <vector>
using namespace std;

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



#endif //STACK_H
