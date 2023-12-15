//
// Created by liuye on 2023/12/15.
//
#include <string>
#include <iostream>
#include <format>

std::string_view extracExtension(const std::string_view filename) {
    return filename.substr(filename.rfind('.'));
}

void handleExtension(const std::string& extension) {

}

void compareString() {
    std::string s1, s2;
    std::cout << "请输入第一个字符串:";
    std::getline(std::cin, s1);

    std::cout << "请输入第二个字符串:";
    std::getline(std::cin, s2);

    std::cout << "字符串1:" << s1 << '\n' << "字符串2:" << s2 << std::endl;

    // 输出比较结果
    if (const auto result = s1 <=> s2; result < nullptr) {
        std::cout << std::format("str1 {} 小于 str2 {} .", s1, s2) << std::endl;
    } else if (result == nullptr) {
        std::cout << std::format("str1 {} 等于 str2 {} .", s1, s2) << std::endl;
    } else {
        std::cout << std::format("str1 {} 大于 str2 {} .", s1, s2) << std::endl;
    }

}

std::string replaceString(std::string haystack, const std::string& needle, const std::string& replacement) {
    auto pos = haystack.find(needle);
    while (pos != std::string::npos) {
        haystack.replace(pos, needle.size(), replacement);
        pos = haystack.find(needle, pos + replacement.size());
    }
    return haystack;
}

/*!
 * \brief replace needle by replacement using StringView
 * \param haystack Raw String
 * \param needle the String need to be found
 * \param replacement the replacement String
 * \return std::string after replacement
 */
std::string replaceStringView(std::string haystack, const std::string_view needle, const std::string_view replacement) {
    auto pos = haystack.find(needle);
    while (pos != std::string::npos) {
        haystack.replace(pos, needle.size(), replacement);
        pos = haystack.find(needle, pos + replacement.size());
    }
    return haystack;
}

int main() {
    system("chcp 65001");
    std::string str= "We think in generalities, but we live in details.";
    const std::size_t pos = str.find("live");
    std::cout << pos << std::endl; // pos 为 33
    const std::string filename {R"(c:\temp\my file.ext)"};
    std::cout << std::format("C++ string: {}", extracExtension(filename)) << std::endl;

    const auto cString { R"(c:\temp\my file.ext)" };
    std::cout << std::format("C string: {}", extracExtension(cString)) << std::endl;

    std::cout << std::format("Literal: {}", extracExtension(R"(c:\temp\my file.ext)")) << std::endl;
    // 无法从string_view 隐式构建一个string，想要实现转换的话，要么使用显式的string转换，要么使用string view的data成员
    handleExtension(extracExtension("my file.ext").data());
    handleExtension(std::string(extracExtension("my file.ext")));

    // 同样，string 与 string view实际上并不是一个数据类型，因此也无法直接连接
    // 应当注意string 与 string view 之间的区别，string view 是拿来用的，不是拿来保存数据的
    using namespace std;
    constexpr auto sv { "My string_view"sv };
    cout << sv << endl;

    auto n = 1;
    const auto sl { format ("Read |{:5}| bytes from |{:5}|", n, "file1.txt")};
    cout << sl << endl;
    cout << format ("|{:{}}| ", "42", 7 ) << endl;
    cout << format ("|{:7}| ", 42) << endl;
    cout << ("--------------------------") << endl;
    // 格式说明符
    cout << "默认:" <<  format("|{:7}|", 42) << endl;
    cout << "左对齐:" << format("|{:<7}|", 42) << endl;
    cout << "右对齐:" << format("|{:>7}|", 42) << endl;
    cout << "居中对齐:" << format("|{:^7}|", 42) << endl;
    cout << ("--------------------------") << endl;
    cout << format("|{:<7}|", 42) << endl;
    cout << format("|{:<+7}|", 42) << endl;
    cout << format("|{:< 7}|", 42) << endl;
    cout << format("|{:< 7}|", -42) << endl;
    cout << ("--------------------------") << endl;
    cout << format("|{:<7d}|", 22) << endl;
    cout << format("|{:<+7b}|", 22) << endl;
    cout << format("|{:<#7b}|", 22) << endl;
    cout << format("|{:< 7X}|", 22) << endl;
    cout << format("|{:<#7X}|", 22) << endl;
    cout << ("--------------------------") << endl;

    constexpr double d {43.1415 / 2.3};
    cout << format("|{:12g}|", d) << endl;
    cout << format("|{:12.2}|", d) << endl;
    cout << format("|{:12.2f}|", d) << endl; // 注意是否有f的区别
    cout << format("|{:12e}|", d) << endl;
    cout << ("--------------------------") << endl;

    constexpr int width {12};
    constexpr int precision {3};
    cout << format("|{2:{0}.{1}f}|", width, precision, d) << endl;
    cout << ("--------------------------") << endl;

    cout << format("|{:012g}|", d) << endl;
    cout << format("|{:012.2}|", d) << endl;
    cout << format("|{:012.2f}|", d) << endl; // 注意是否有f的区别
    cout << format("|{:012e}|", d) << endl;
    cout << ("--------------------------") << endl;
    cout << ("--------------------------") << endl;
    try { cout << format("An integer: {:12.2f}", 5.0);} catch (const format_error& caught_exception) {
        cout << caught_exception.what();
    }
    cout << ("--------------------------") << endl;
    // compareString();

}