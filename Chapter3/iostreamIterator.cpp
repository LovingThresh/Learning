//
// Created by liuye on 2023/12/16.
//
#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
#include<string>

int main() {
    using namespace std;
    istream_iterator<string> in_iter(cin); // 输入
    const istream_iterator<string> eof;
    const string exitString {"exit"};
    vector<string> words;
    while (in_iter != eof) {
        if (*in_iter == exitString) {
            break;
        }
        words.push_back(*in_iter);
        cout << *in_iter << endl;
        ++in_iter; // return *this
    }
    cout << "words.size() = " << words.size() << endl;
    ranges::sort(words.begin(), words.end());
    const ostream_iterator<string> out_iter(cout, " ");
    ranges::unique_copy(words.begin(), words.end(), out_iter);

    return 0;
}
