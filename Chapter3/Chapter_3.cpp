//
// Created by liuye on 2023/12/4.
//
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void print_dict_count(const map<string, int> &words) {
    for (auto & [key, value] : words) {
        cout << "keys: " << key << "    " << "value: " << value << endl;
    }
}

void insert_dict_exclusion(const set<string> &word_exclusion, map<string, int> &words, const string &tword) {
    if (word_exclusion.count(tword)) {
    }
    else {
        words[tword]++;
    }
}

// 读取文本文件，定义word_exclusion, words, tword
map<string, int> file2dict(const string &file_name) {
    map<string, int> words;
    const set<string> word_exclusion = {"a", "an", "but", "or", "the", "and"};
    if (ifstream infile(file_name); !infile)
        {cerr << "File Can't Open!" << endl;}
    else {
        string t_word;
        while (infile >> t_word) {
            insert_dict_exclusion(word_exclusion, words, t_word);
        }
    }
    return words;
}

//读取文本文件，以vector形式保持，定义vector, element
vector<string> file2vec(const string &file_name) {
    vector<string> vec;
    if (ifstream infile(file_name); !infile)
        {cerr << "File Can't Open!" << endl;}
    else {
        string v_word;
        while (infile >> v_word) {
            vec.push_back(v_word);
        }}
    return vec;
}

// 定义一个函数对象
struct CompareStringLength {
    bool operator()(const string &a, const string &b) const {
        return a.length() < b.length();
    }
};

void sort_vector_print(vector<string> &vec) {
    sort(vec.begin(), vec.end(), CompareStringLength());
    for (const auto &element : vec) {
        cout << element << "    ";
    }
}

int main() {
    vector<string> vec = {"apple", "banana", "cherry", "date"};
    sort_vector_print(vec);
}


// 单词计数功能 (file2dict 函数):
// 这个函数从给定的文件名读取文本，并将每个单词的出现次数计数到一个 map<string, int> 中。
// 它使用了一个排除词集合 word_exclusion 来忽略某些常见的单词（如 "a", "an", "but" 等）。
// 这个函数逐个读取文本中的单词，并使用 insert_dict_exclusion 函数来判断是否应该将单词计入计数。

//
// 单词排除功能 (insert_dict_exclusion 函数):
// 此函数用于检查一个单词是否在排除词集合中。如果不在，它会在 words 映射中增加该单词的计数。这有助于过滤掉不想计数的单词。

//
// 打印单词计数 (print_dict_count 函数):
// 用于输出单词计数映射中的每个条目。对于映射中的每个键值对，它会打印出键（单词）和对应的值（计数）。

//
// 文件到向量转换 (file2vec 函数):
// 这个函数读取一个文本文件，并将其内容作为单词的向量返回。它逐个读取文件中的每个单词，然后将它们添加到一个 vector<string> 中。
//
// 自定义排序和打印功能 (sort_vector_print 函数和 CompareStringLength 结构体):
// CompareStringLength 是一个定义了 () 操作符的结构体，用于比较两个字符串的长度。
// sort_vector_print 函数使用这个函数对象来对一个 vector<string> 进行排序，然后打印排序后的结果。
// 它将 vector 的元素按照长度排序并输出。

//
// 主函数 (main 函数):
// 作为程序的入口点，它创建了一个 vector<string> 示例并调用 sort_vector_print 函数来演示排序和打印功能。











