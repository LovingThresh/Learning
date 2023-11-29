//
// Created by liuye on 2023/11/17.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
bool fibon_elem(const int pos, int &elem)
{
    using namespace std;
    // 检查位置值是否合理
    if (pos <= 0 || pos > 46) {
        elem = 0;
        cout << "位置不能小于0或者大于46" << endl;
        return false;
    }
    // 初始位置的元素值为1
    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int ix = 3; ix <= pos; ++ix) { //前缀是运算对象本身，后缀是修改前的对象值
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    return true;
}

void fibon_print_serise()
{
    using namespace std;
    int number;
    vector<int> pos;
    string pos_str;

    cout << "请输入一串位置参数：";
    getline(cin, pos_str);
    istringstream iss(pos_str);
    while (iss >> number) {
        pos.push_back(number);
    }
    int elem;
    for (const int po : pos) {
        if (fibon_elem(po, elem)) { // &elem 传入的是 elem 的地址
            cout << "位置" << po << "的元素是" << elem << endl;
        } else {
            cout << "对应位置的元素不存在" << endl;
        }
    }
}
bool check_input(std::istream& in){
    using namespace std;
    if (in.fail()){
        cout << "输入不合法 程序退出" << endl;
        in.clear();
        in.ignore(1024, '\n');
        return false;
    }
    return true;

}
void fibon_print_continue(){
    using namespace std;
    bool go_on = true;
    int pos, elem;
    while (go_on){
        cout << "请输入位置：";
        cin >> pos;
        // 检查输入是否合法
        if (!check_input(cin)){
            break;
        }

        if (fibon_elem(pos, elem)) {
            cout << "位置" << pos << "的元素是" << elem << endl;
        } else {
            cout << "对应位置的元素不存在" << endl;
        }
        cout << "是否继续？(y/n)";
        char c;
        cin >> c;
        // 检查输入是否合法
        if (!check_input(cin)){
            break;
        }
        if (c == 'n' || c == 'N'){
            go_on = false;
        } else if (c != 'y' && c != 'Y'){
            cout << "无效输入，程序将继续执行。输入'n'停止。" << endl;
        }
    }
}

// 练习 2.2

