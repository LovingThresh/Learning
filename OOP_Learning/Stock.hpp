//
// Created by liuye on 2023/11/20.
//

#ifndef LEARNING_STOCK_H
#define LEARNING_STOCK_H

#include <string>
class Stock {
private:
    std::string company;
    // char *company;
    long shares;
    double share_val;
    double total_val{}; // 初始化total_val
    void set_tot() {total_val = shares* share_val;}
public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
    Stock(const std::string &co, long n, double pr);
};


#endif //LEARNING_STOCK_H
