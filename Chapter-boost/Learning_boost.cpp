//
// Created by liuye on 2023/12/7.
//
#include <boost/json.h>
#include <iostream>

int main() {

    // 创建一个JSON对象
    boost::json::object obj;
    obj["key"] = "value";

    // 转换为字符串
    const std::string json_str = boost::json::serialize(obj);

    // 打印JSON字符串
    std::cout << json_str << std::endl;

    return 0;
}
