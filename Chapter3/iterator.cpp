//
// Created by liuye on 2023/12/3.
//
#include <vector>
#include <iostream>
void explore_iterator() {
    using namespace std;
    const vector v {1, 2, 3, 4, 5, 6, 7};
    const auto i = begin(v);
    const auto e = end(v);
    cout << *i << endl;
    cout << *(i + 2) << endl;
    cout << *(e) << endl;

}

int main() {
    explore_iterator();
    return 0;
}