//
// Created by liuye on 2023/12/7.
//

// #include <boost/json.hpp>
#include <boost/json/src.hpp>
#include <boost/math/ccmath/sqrt.hpp>
#include <iostream>

int main() {
    // 创建一个 JSON 对象
    boost::json::object person;
    std::cout << boost::math::ccmath::sqrt(10) << std::endl;
    // 向 JSON 对象添加属性
    person["name"] = "Alice";
    person["age"] = 30;
    person["city"] = "New York";

    // 将 JSON 对象转换为字符串
    const std::string jsonStr = boost::json::serialize(person);

    // 打印生成的 JSON 字符串
    std::cout << jsonStr << std::endl;

    return 0;
}
