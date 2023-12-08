//
// Created by liuye on 2023/12/8.
//
#include  <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main() {
    cout << "Testing the Employee class." << endl;
    Employee emp {"Jane", "Doe"};
    emp.setFirstName("john");
    emp.setLastName("Doe");
    emp.setEmployeeNumber(71);
    emp.setSalary(50'000);
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.display();
    return 0;
}