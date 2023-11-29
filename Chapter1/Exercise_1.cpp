//
// Created by liuye on 2023/11/10.
//
#include <cstring>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <Eigen/Core>
#include <algorithm>
/*
 * getline(cin, user_name) 适用于处理字符串，并且不需要指定字符串的最大长度
 * cin.getline(user_name_char, sizeof user_name_char) 适用于处理字符数组，并且需要指定字符数组的最大长度
 */
// 练习 1.1
void pointer_array() {
    using namespace std;
    short dates[4], *pti, index;
    double bills[4], *ptf;
    cout << "               short     double\n";
    for (index = 0; index < 4; index++)
        cout << "array name + " << index << "  " << dates + index << " " // 思考dates的含义,dates是数组名(指针)
             // 数组名是数组的首地址
             << bills + index << endl;
    // short 2 bits

    pti = dates;
    ptf = bills;
    cout << "\n               short      double\n";
    for (index = 0; index < 4; index++)
        cout << "pointers + " << index << "  " << pti + index << " "
             << ptf + index << endl;
    // double 8 bits
}

// 练习 1.2
void pointer_visit_array(){
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0}, *pw = wages; //pw是指针变量, *pw是指针变量指向的值
    cout << "\npw = " << pw << ", *pw = " << *pw << endl;

    pw = pw + 1;
    cout << "\nadd 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    cout << "size of wages array = " << sizeof(wages);
    cout << "\nsize of pw pointer  = " << sizeof(pw);
}

// 练习 1.3
void pointer_string(){
    using namespace std;
    char animal[20] = "bear"; // "bear"的末位是'\0'
    char new_animal[20];
    const char *bird = "wren";
    char *ps;
    double *pd;
    int *pi;

    cout << sizeof(ps) << endl; // 8
    cout << sizeof(pd) << endl; // 8
    cout << sizeof(pi) << endl; // 8

    cout << '\n' << animal << " and " << bird << "\n";
    // cout << ps << endl; // 随处地址，不知道它指向什么东西，输出的东西是完全不可控的
    // cout << sizeof(ps) << endl; // 只有指针指向一个合法的空间，才能够对其进行操作

    cout << "Enter a kind of animal:"; // 这个空格会转移到下一个输入，为什么？

    cin >> animal; // cin读取到空格就停止 , animal chanes
    // cin >> ps; // cin读取到空格就停止
    ps = animal;


    cout << ps << "!\n";
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl; // (int *) animal强制类型转换
    cout << ps << " at " << (int *) ps << endl; // (int *) ps强制类型转换

    ps = new char[strlen(animal) + 1]; // 新申请到的内存空间，不会被初始化
    strcpy(ps, animal); // 将animal的内容复制到ps指向的内存空间
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;

    // cout << strlen(animal) << endl;
    delete [] ps; // 释放ps指向的内存空间
}

// 练习 1.4
void dynamic_strc(){
    struct inflatable{
        char name[20];
        float volume;
        double price;
    };
    using namespace std;
    inflatable *ptr; // 申请一个inflatable大小的内存空间
    ptr = new inflatable; // 申请一个inflatable大小的内存空间

    (*ptr).volume = 10.0; // (*ptr)是一个inflatable类型的变量
    // -> 是一个运算符，用于访问结构体指针指向的成员
    ptr -> volume = 10.0; // ptr->volume是一个inflatable类型的变量

    delete ptr; // 释放ptr指向的内存空间
}

// 练习 1.5
void get_user_name() {
    using namespace std;
    string user_name;
    char user_name_char[256] = "";

    cout << "user_name_size: " << user_name.size() << endl;
    cout << "user_name_char_size: " << strlen(user_name_char) << endl;

    cout << "Please enter your name (Pleses > 2 characters):";
    // cin >> user_name;
    getline(cin, user_name);

    while (user_name.size() <= 2) {
        cout << "The charater size of user_name is less than 2." << endl;
        cout << "Please enter your name (Pleses > 2 characters):";
        // cin >> user_name;
        getline(cin, user_name);
    }
    cout << "Success!" << endl;
    cout << "Turn to Next Mode" << endl;

    cout << "Please enter your name (Pleses > 2 characters):";
    // cin >> user_name_char;
    cin.getline(user_name_char, sizeof user_name_char);

    while (strlen(user_name_char) <= 2) {
        cout << "The charater size of user_name is less than 2." << endl;
        cout << "Please enter your name (Pleses > 2 characters):";
        cin.getline(user_name_char, sizeof user_name_char);
    }
    cout << "Success!" << endl;

    cout << '\n' << "Hello, "
         << user_name << " ... and goodbye!\n";
    cout << '\n' << "Hello, "
         << user_name_char << " ... and goodbye!\n";
}

// 练习 1.6
void get_int_number(){
    using namespace std;
    const int max_array_size = 100;

    int number;
    int number_array[max_array_size];
    int number_sum_vector = 0;
    int number_sum_array = 0;
    float number_average_vector;
    float number_average_array;

    vector<int> int_number_vector;

    cout << "Please enter a series of integer numbers (the first number):" << endl;
    while (cin >> number){
        int_number_vector.push_back(number);
        cout << "Please enter a series of integer numbers (enter no-integer to end, e.g. q):" << endl;
    }
    // 如果你直接按下 Enter 键，可能会导致无限循环等待输入
    if (int_number_vector.empty()) {
        cout << "No integer numbers were entered." << endl;
        return;
    }

    cout << "The size of int_number_vector is " << int_number_vector.size() << endl;

    // 范围-based for 循环（也称为范围for循环或foreach循环），用于遍历容器中的元素
    for (int i : int_number_vector){
        number_sum_vector += i;
    }
    number_average_vector = static_cast<float> (number_sum_vector) / static_cast<float> (int_number_vector.size());

    cout << "The sum of int_number_vector is " << number_sum_vector << endl;
    cout << "The average of int_number_vector is " << number_average_vector << endl;

    cout << "Please enter a series of integer numbers (the first number):" << endl;
    int i = 0;

    while (cin >> number){
        if (i < max_array_size){
        number_array[i] = number;
        i++;
        cout << "Please enter a series of integer numbers (enter no-integer to end, e.g. q):" << endl;
    } else {
        cout << "The size of number_array is " << max_array_size << endl;
        break;
        }
    }

    if (i == 0) {
        cout << "No integer numbers were entered." << endl;
        return;
    }

    for (int j = 0; j < i; j++){
        number_sum_array += number_array[j];
    }
    number_average_array = static_cast<float> (number_sum_array) / static_cast<float> (i);

    cout << "The sum of number_array is " << number_sum_array << endl;
    cout << "The average of number_array is " << number_average_array << endl;

}

// 练习 1.7
// 以空格为间隔符，读取字符串
void string_read() {
    using namespace std;
    ifstream infile("D:/development/CPP_Projects/Learning/Chapter1/string_exercise.txt");
    ofstream outfile("D:/development/CPP_Projects/Learning/Chapter1/string_exercise_out.txt");
    vector<string> infile_string;
    string character;


    if(!infile)
    {
        cerr << "File Can't Open!" << endl;
    }

    else
    {
         while (infile >> character)
        {
            infile_string.push_back(character);
        }
        for (const auto & i : infile_string)
        // for (size_t i = 0; i < infile_string.size(); ++i)
        {
            cout << i << " ";
        }
        cout << endl;
        sort(infile_string.begin(), infile_string.end());
    }

    if (!outfile)
    {
        cerr << "Oops! Unable to save session data!\n";
    }
    else
    {
        for (const auto & i : infile_string)
        {
            outfile << i << " ";
        }
    }
}

// 读取字符串的每个字符
void each_string_read() {
    using namespace std;
    ifstream infile("D:/development/CPP_Projects/Learning/Chapter1/string_exercise.txt");
    ofstream outfile("D:/development/CPP_Projects/Learning/Chapter1/string_exercise_out.txt");
    vector<string> infile_string;
    char character;


    if(!infile)
    {
        cerr << "File Can't Open!" << endl;
    }

    else
    {
        while (infile.get(character)){
            string char_string(1, character);
            infile_string.push_back(char_string);
        }
        for (const auto & i : infile_string)
        // for (size_t i = 0; i < infile_string.size(); ++i)
        {
            cout << i << "|";
        }
        cout << endl;
        sort(infile_string.begin(), infile_string.end());
    }

    if (!outfile)
    {
        cout << "Oops! Unable to save session data!\n";
    }
    else
    {
        for (const auto & i : infile_string)
        {
            outfile << i << " ";
        }
    }
}

// 练习 1.8
void guess_number(){
    using namespace std;
    bool next_seq = true;
    bool go_for_it = true;
    bool got_it = false;
    int next_elem = 2;
    int num_tries = 0;
    int num_rights = 0;

    string string_seq[4] = {"Don't worry, you're getting closer with each guess. Keep trying!",
                            "It's just a game of numbers, and you're doing great. Guess again!",
                            "Remember, every wrong guess is a step towards the right one. You've got this!",
                            "Stay positive! The fun is in the challenge, and your next guess might be the one!"};

    const int seq_size = 18;
    int algorithm_seq[seq_size] = {1, 2, 3, // Fibonacci sequence
                              3, 4, 7, // Lucas sequence
                              2, 5, 12, // Pell sequence
                              3, 6, 10, // Triangular sequence
                              4, 9, 16, // Square sequence
                              5, 12, 21}; // Pentagonal sequence

    while (next_seq){
        // 为用户显示序列
        cout << "The first elem in this sequence is: " << algorithm_seq[next_elem - 2] << endl;
        cout << "The second elem in this sequence is: " << algorithm_seq[next_elem - 1] << endl;
        cout << "Please enter the next elem in this sequence: " << endl;
        while (!got_it && go_for_it){
            int user_guess;
            cin >> user_guess;
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter an integer!" << endl;
                continue;
            }
            if (user_guess < 0){
                cout << "Please enter a positive integer!" << endl;
                continue;
            }
            num_tries++;
            if (user_guess == algorithm_seq[next_elem]){
                got_it = true;
                num_rights++;
                cout << "Congratulations! You got it!" << endl;
                if (next_elem < seq_size - 1){
                next_elem += 3;}else{
                    cout << "You have finished all the sequences!" << endl;
                }
            } else{
                cout << "Sorry! Your answer is wrong!" << endl;
                switch (num_tries) {
                    case 1:
                        cout << string_seq[0] << endl;
                        break;
                    case 2:
                        cout << string_seq[1] << endl;
                        break;
                    case 3:
                        cout << string_seq[2] << endl;
                        break;
                    case 4:
                    default:
                        cout << string_seq[3] << endl;
                        break;
                }
                cout << "Do you want to try again? (Y/N)" << endl;
                char usr_rsp;
                cin >> usr_rsp;
                if (usr_rsp == 'N' || usr_rsp == 'n'){
                    go_for_it = false;
                    // give the right answer
                    cout << "Thanks! The right answer is: " << algorithm_seq[next_elem] << endl;
                }
            }
        }
        cout << "Do you want to try next sequence? (Y/N)" << endl;
        char try_again;
        cin >> try_again;
        if ((cin.fail())){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter Y or N!" << endl;
            continue;
        }
        if (try_again == 'N' || try_again == 'n'){
            next_seq = false;
        } else{
            got_it = false;
            go_for_it = true;
        }
    }
    cout << "You have tried " << num_tries << " times in total." << endl;
    cout << "You have got " << num_rights << " times in total." << endl;
}

// Eigen库的使用
int core() {
    const double QUARTER_PI = 45.0 * M_PI / 180.0;
    const double HALF_PI = 90.0 * M_PI / 180.0;

    Eigen::Vector<double, 3> point(2, 1, 1);
    Eigen::Matrix3d matrix45;
    Eigen::Matrix3d matrix90;

    matrix45 << cos(QUARTER_PI), -sin(QUARTER_PI), 1,
            sin(QUARTER_PI), cos(QUARTER_PI), 2,
            0, 0, 1;
    matrix90 << cos(HALF_PI), -sin(HALF_PI), 0,
            sin(HALF_PI), cos(HALF_PI), 0,
            0, 0, 1;

    std::cout << "(" << point.x() << "," << point.y() << "," << point.z() << ")" << std::endl;
    point = matrix45 * point;
    std::cout << "(" << point.x() << "," << point.y() << "," << point.z() << ")" << std::endl;
    return 0;
}