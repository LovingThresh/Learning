//
// Created by liuye on 2023/11/27.
//

#include "Stack.h"
namespace regular {
    Stack::Stack() {
        _stack = {};
    }

    Stack::Stack(const int len) {
        const vector<string> initialVector(len);
        _stack = initialVector;
    }

    inline
    bool Stack::empty() const {
        return _stack.empty();
    }

    inline
    bool Stack::full() const {
        return _stack.size() == _stack.max_size();
    }

    // 当const应用于类的成员函数时，意味着不能修改类的成员变量
    bool Stack::pop(string &elem) {
        if (empty()) {
            return false;
        }

        elem = _stack.back();
        _stack.pop_back();
        return true;

    }

    bool Stack::peek(string &elem) const {
        if (empty()) {
            return false;
        }
        elem = _stack.back();
        return true;
    }

    bool Stack::push(const string &elem){
        if (full()) {
            return false;
        }
        _stack.push_back(elem);
        return true;
    }
}

namespace stack_templated {
    template<class Type, int Max>
    bool Stack_Temlated<Type, Max>::push(const Type&item) {
        if ( top < Max ) {
            items[top++] = item;
            return true;
        }
        return false;
    }

    template<class Type, int Max>
    bool Stack_Temlated<Type, Max>::pop(Type&item) {
        if ( top > 0 ) {
            item = items[--top];  //
            return true;
        }
        return false;
    }




}