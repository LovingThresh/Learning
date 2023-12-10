#include <string>
#include <iostream>

#include "./Chapter3.hpp"

const int* findvalue_const_ptr(const std::vector<int> &vec, const int value) {
    for (const int vector_elem: vec) {
        if (vector_elem == value) {
            const auto* result = new int(vector_elem);
            return result;
        }
    }
    return nullptr;
}

int* findvalue_ptr(const std::vector<int> &vec, const int value) {
    for (const int vector_elem: vec) {
        if (vector_elem == value) {
            auto* result = new int(vector_elem);
            return result;
        }
    }
    return nullptr;
}

const int* findvalue_const_index(const std::vector<int> &vec, const int value) {
    for (const int & i : vec) {
        if (i == value) {
            return &i;
        }
    }
    return nullptr;
}

template <typename elemType>
elemType* findvalue_ptr(const std::vector<elemType> &vec, const elemType value) {
    for (const elemType vector_elem: vec) {
        if (vector_elem == value) {
            auto* result = new elemType(vector_elem);
            return result;
        }
    }
    return nullptr;
}

template <typename elemType>
const elemType* find(const elemType *first, const elemType *last, const elemType &value) {
    if (!first || !last) {
        return nullptr;
    }
    while (first != last) {
        if (*first == value) {
            return first;
        }
        ++first;
    }
    return nullptr;
}

template <typename elemType>
elemType* begin(const std::vector<elemType> &vec) {
    return vec.empty() ? nullptr : &vec[0];
}

template <typename elemType>
elemType* end(const std::vector<elemType> &vec) {
    return vec.empty() ? nullptr : &vec[vec.size()];
}

// For test
void find_value() {
    using namespace std;
    constexpr int  ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    constexpr double da[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    const std::string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};
    const std::string string_sample = "eeyore";
    const int *ip = find(ia, ia + 8, 2);
    cout << "Find: " << *ip << endl;
    const double *dp = find(da, da + 6, 4.4);
    cout << "Find: " << *dp << endl;
    const std::string *sp = find(sa, sa + 4, string_sample);
    cout << "Find: " << *sp << endl;
}