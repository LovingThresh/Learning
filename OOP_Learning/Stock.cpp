//
// Created by liuye on 2023/11/20.
//
#include <iostream>
#include "Stock.h"

void Stock::acquire(const std::string &co, long n, double pr) {

}

void Stock::buy(long num, double price) {

}

void Stock::sell(long num, double price) {

}

void Stock::update(double price) {

}

void Stock::show() {

}


Stock::Stock(const std::string &co, long n, double pr=0.) {
    company = co;
    if (n < 0){
        std::cout << "Number of shares can't be negative;" << company << "share set to 0.\n";
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}


