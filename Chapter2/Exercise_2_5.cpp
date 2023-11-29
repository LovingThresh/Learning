#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include <chrono>
template <typename T>
T max(const T A, const T B) {
    const T result = A > B? A : B;
    return result;
}

template<typename T>
T max(const std::vector<T> &vectorA) {
    T result = std::numeric_limits<T>::min();
    for (T num : vectorA) {
        result = num > result? num : result;
    }
    return result;
}

template <typename T>
std::vector<T> max(const std::vector<T> &vectorA, const int vector_size) {
    std::vector<T> result = vectorA;
    std::sort(result.begin(), result.end());
    result.resize(vector_size);
    return result;
}

// int max(int numA, int numB);
// double max(double numA, double numB);
// char max(char charA, char charB);
// int max(const std::vector<int> &vectorA);
// double max(const std::vector<double> &vectorA);
// char max(const std::vector<char> &vectorA);
// std::vector<int> max(const std::vector<int> &vectorA, int vector_size);
// std::vector<double> max(const std::vector<double> &vectorA, int vector_size);
// std::vector<char> max(const std::vector<char> &vectorA, int vector_size);

// int max(const int numA, const int numB) {
//     const int result = numA > numB ? numA : numB;
//     return result;
// }
//
// double max(const double numA, const double numB) {
//     const double result = numA > numB ? numA : numB;
//     return result;
// }
//
// char max(const char charA, const char charB) {
//     const char result = charA > charB ? charA : charB;
//     return result;
// }

// int max(const std::vector<int> &vectorA) {
//     int result = std::numeric_limits<int>::min();
//     for (int num : vectorA) {
//         result = num > result? num : result;
//     }
//     return result;
// }
//
// double max(const std::vector<double> &vectorA) {
//     double result = std::numeric_limits<double>::min();
//     for (double num : vectorA) {
//         result = num > result? num : result;
//     }
//     return result;
// }
//
// char max(const std::vector<char> &vectorA) {
//     char result = std::numeric_limits<char>::min();
//     for (char num : vectorA) {
//         result = num > result? num : result;
//     }
//     return result;
// }

// std::vector<int> max(const std::vector<int> &vectorA, const int vector_size) {
//     std::vector<int> result = vectorA;
//     std::sort(result.begin(), result.end());
//     result.resize(vector_size);
//     return result;
// }
//
// std::vector<double> max(const std::vector<double> &vectorA, const int vector_size) {
//     std::vector<double> result = vectorA;
//     std::sort(result.begin(), result.end());
//     result.resize(vector_size);
//     return result;
// }
//
// std::vector<char> max(const std::vector<char> &vectorA, const int vector_size) {
//     std::vector<char> result = vectorA;
//     std::sort(result.begin(), result.end());
//     result.resize(vector_size);
//     return result;
// }

int main() {

    const auto start = std::chrono::high_resolution_clock::now();

    // using namespace std;

    // 测试 max 函数
    constexpr int numA = 5, numB = 8;
    constexpr double doubleA = 3.14, doubleB = 2.71;
    constexpr char charA = 'A', charB = 'B';

    std::cout << "max(int): " << max(numA, numB) << std::endl;
    std::cout << "max(double): " << max(doubleA, doubleB) << std::endl;
    std::cout << "max(char): " << max(charA, charB) << std::endl;

    // 测试 max 函数对向量的操作
    const std::vector<int> intVector = {3, 1, 7, 2, 5};
    const std::vector<double> doubleVector = {3.14, 2.71, 1.618, 2.0};
    const std::vector<char> charVector = {'A', 'C', 'B', 'D', 'E'};

    std::cout << "max(vector<int>): " << max(intVector) << std::endl;
    std::cout << "max(vector<double>): " << max(doubleVector) << std::endl;
    std::cout << "max(vector<char>): " << max(charVector) << std::endl;

    // 测试 max 函数返回前 n 个最大值
    constexpr int n = 3;

    const std::vector<int> intVectorMax = max(intVector, n);
    const std::vector<double> doubleVectorMax = max(doubleVector, n);
    const std::vector<char> charVectorMax = max(charVector, n);

    std::cout << "max(vector<int>, " << n << "): ";
    for (const int num : intVectorMax) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "max(vector<double>, " << n << "): ";
    for (const double num : doubleVectorMax) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "max(vector<char>, " << n << "): ";
    for (const char c : charVectorMax) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed time in milliseconds: " << duration.count() << std::endl;

// #include <iostream>


    constexpr int x = 42;   // 声明一个整数变量 x 并初始化为 42
    const int* p = &x;  // 声明一个整数指针变量 p，将其初始化为 x 的地址

    const bool result = (*p == x); // 比较 *p 和 x 的值
    std::cout << "Comparison result: " << result << std::endl; // 输出结果
    // Comparison result: 1
    return 0;
}