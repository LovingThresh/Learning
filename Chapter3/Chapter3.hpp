//
// Created by liuye on 2023/12/1.
//

#ifndef CHAPTER3_H
#define CHAPTER3_H
#include <vector>

int* findvalue_ptr(const std::vector<int> &vec, int value);
const int* findvalue_const_ptr(const std::vector<int> &vec, int value);
const int* findvalue_const_index(const std::vector<int> &vec, int value);

template <typename elemType>
elemType* findvalue_ptr(const std::vector<elemType> &vec, elemType value);

template <typename elemType>
const elemType* find(const elemType *first, const elemType *last, const elemType &value);

template <typename elemType>
elemType* begin(const std::vector<elemType> &vec);

template <typename elemType>
elemType* end(const std::vector<elemType> &vec);

void find_value();
#endif //CHAPTER3_H

