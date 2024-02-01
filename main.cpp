#include <iostream>
#include <limits>
// #include "Chapter2/Exercise_2.h"
#include "OOP_Learning/Stock.hpp"
// #include "boost/math/complex.hpp"
#include <concepts>

template<typename T>
concept Addable = requires(T a, T b)
{
    a + b;
};

double Fibonacci(const unsigned int n) {
    using namespace std;
    double f_n = 0;
    double f_n1 = 1;
    double f_n2 = 1;
    bool find_int = false;

    constexpr unsigned int max_unsigned_int = numeric_limits<unsigned int>::max();
    constexpr int max_int = numeric_limits<int>::max();

    for (int k = 3; k <= n; k++) {
        f_n = f_n1 + f_n2;
        f_n2 = f_n1;
        f_n1 = f_n;
        if (f_n > max_int && !find_int) {
            cout << "max int 在Fibonacci数列的位置为" << k - 1 << endl;
            find_int = true;
        }
        if (f_n > max_unsigned_int) {
            cout << "max unsigned int 在Fibonacci数列的位置为" << k - 1 << endl;
            break;
        }
    }
    return f_n;
}

// tex.c
#include <cstdio>

int main() {
    using namespace std;
    system("chcp 65001");
    cout << "Hello, World!" << endl;
    printf("Hello World\n");
    // Chapter1 ------------------
    // pointer_array();
    // pointer_visit_array();
    // pointer_string();
    // dynamic_strc();
    // get_user_name();
    // get_int_number();
    // core();
    // string_read();
    // each_string_read();
    // guess_number();
    // Chapter2 ------------------
    // fibon_print_serise();
    // fibon_print_continue();
    // cout << Fibonacci(1024) << endl;
    // for (int i = 0; i<10; i++){
    //     cout << i << endl;
    // }
    // for (int i = 0; i < 10; ++i) {
    //     cout << i << endl;
    // }
    // Stock fluffy_the_cat;
    // Stock *ps1 = &fluffy_the_cat, *ps2;
    // ps1 -> acquire("NanoSmart", 20, 12.50);
    // ps1 -> show();
    // ps2 = new Stock;
    // ps2 -> acquire("NanoSmart", 20, 12.50);
    // ps2 -> show();
    // delete ps2;
    // Stock st1("comp1", 20, 3.4);

    // static_assert(Addable<int>);

    constexpr int myIntArray[10]{};
    std::cout << myIntArray << std::endl;
    std::cout << myIntArray[0] << std::endl;
    std::cout << &myIntArray[0] << std::endl;
    return 0;
}
