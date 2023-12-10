//
// Created by liuye on 2023/12/8.
//
#include <iostream>
#include "Database.hpp"

using namespace std;
using namespace Records;

int main() {
    Database myDB;
    Employee& emp1 { myDB.addEmployee("Grey", "Wallis") };
    emp1.fire();

    Employee& emp2 { myDB.addEmployee("Marc", "White") };
    emp2.setSalary(100'000);

    Employee& emp3 { myDB.addEmployee("John", "Doe")};
    emp3.setSalary(10'000);
    emp3.promote();

    cout << "all employees: " << endl;
    myDB.displayAll();

    cout << "Current employees: " << endl;
    myDB.displayCurrent();

    cout << "Former employees: " << endl;
    myDB.displayFormer();


}







