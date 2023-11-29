//
// Created by liuye on 2023/11/24.
//
#include <vector>
#include <cassert>
#include <iostream>
#include <limits>
#include <cmath>

bool check_input(std::istream& in) {
    using namespace std;
    if (in.fail()){
        cout << "输入不合法 程序退出" << endl;
        in.clear();
        in.ignore(1024, '\n');
        return false;
    }
    return true;
}

void FindPentagonalBoundary() {
    using namespace std;
    constexpr double number = 24 * static_cast<double>(std::numeric_limits<int>::max());
    int const result = (1 + static_cast<int>(std::sqrt(1 + number))) / 6 ;
    cout << "The Boundary of Int:" << result << endl;
}

int Pentagonal(const int n) {
    assert(n > 0 || n <= 37837);
    return n * (3 * n - 1) / 2;
}

void PentagonalPost(std::vector<int> &PentagonalVector, const int numVector) {
    using namespace std;
    int num_operations = 0;
    for (int i = static_cast<int>(PentagonalVector.size()) + 1; i <= numVector; i++) {
        PentagonalVector.push_back(Pentagonal(i));
        num_operations++;
    }
    cout << "Number of operations is " << num_operations << endl;
}

void PentagonalPrint(const std::vector<int> &PentagonalVector) {
    using namespace std;
    int i = 1;
    for (const int elem: PentagonalVector) {
        cout << "位置" << i << "的元素的值是" << elem << endl;
        i++;
    }
}

inline void PentagonalPrintPoint(const std::vector<int> *PentagonalVector, const int numPos) {
    using namespace std;
    for (int i = 1; i <= numPos; i++) {
        cout << "位置" << i << "的元素的值是" << (*PentagonalVector)[i - 1] << endl;
    }
}

const std::vector<int>* PentagonalVectorPointer(const int numVector) {
    using namespace std;
    static std::vector<int> pentagonalVector; // 静态局部的 vector
    int num_operations = 0;

    // 检查 vector 是否已经包含 Pentagonal 数列的元素
    if (pentagonalVector.size() >= numVector) {
        return &pentagonalVector; // 直接返回现有的 vector
    }

    // 如果 vector 不包含足够多的元素，继续生成 Pentagonal 数列的元素并添加到 vector 中
    for (int i = static_cast<int>(pentagonalVector.size()) + 1; i <= numVector; i++) {
        pentagonalVector.push_back(Pentagonal(i));
        num_operations++;
    }

    cout << "Number of operations is " << num_operations << endl;

    return &pentagonalVector; // 返回指向 vector 的指针
}

int PentagonalElem(const std::vector<int> &PentagonalVector, const int elemPos) {
    const int Pentagonalelem = PentagonalVector[elemPos];
    return Pentagonalelem;
}

// constexpr int MAX_PENTAGONAL = 100; // 定义 Pentagonal 数列的最大元素个数

// std::vector<int>* PentagonalVectorPointer(const std::vector<int> &PentagonalVector) {
//     static std::vector<int> pentagonalVector; // 局部静态的 vector
//
//     // 检查 vector 是否已经包含 Pentagonal 数列的元素
//     if (pentagonalVector.empty()) {
//         // 如果为空，生成 Pentagonal 数列的元素并添加到 vector 中
//         pentagonalVector = PentagonalVector;
//     }
//
//     return &pentagonalVector; // 返回指向 vector 的指针
// }

int main() {

    using namespace std;
    int numDefind;
    vector<int> P_Vector= {};
    system("chcp 65001");
    // FindPentagonalBoundary();
    bool getPentagonal = true;
    // system("pause");
    while (getPentagonal){
        cout << "Please give me the num N:";
        cin >> numDefind;
        check_input(cin);
        const vector<int> *P_Vector_Point = PentagonalVectorPointer(numDefind);
        // if (last_num <= numDefind) {
        //     const vector<int> first_P_Vector(P_Vector.begin(), P_Vector.begin() + last_num);
        //     P_Vector = first_P_Vector;
        //     P_Vector.clear();
        //     PentagonalPost(P_Vector, numDefind);
        // }
        // else {
        //     P_Vector.resize(numDefind);
        //     vector<int> *P_Vector_Point;
        //     cout << "last_num为" << last_num << endl;
        // }
        // cout << &P_Vector << endl;
        // cout << &numDefind << endl;
        // PentagonalPrint(P_Vector);
        PentagonalPrintPoint(P_Vector_Point, numDefind);
        // cout << "静态数组的指针地址为" << PentagonalVectorPointer(P_Vector) << endl;
        // cout << "原始数值的指针地址为" << &P_Vector << endl;
        cout << "是否继续？(y/n)";
        char c;
        cin >> c;
        // 检查输入是否合法
        if (!check_input(cin)){break;}
        if (c == 'n' || c == 'N'){
            getPentagonal = false;}
        else if (c != 'y' && c != 'Y'){
            cout << "无效输入，程序停止。" << endl;
            getPentagonal = false;}
    }
    // system("pause");
    return 0;
}
