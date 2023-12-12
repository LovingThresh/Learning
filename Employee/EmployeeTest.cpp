//
// Created by liuye on 2023/12/8.
//
#include <array>
#include <vector>
#include <iostream>
#include "Employee.hpp"

using namespace std;
using namespace HR;

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
    std::array  Employee_array {Employee {"Grey", "Wallis"},
                                Employee {"Marc", "White"},
                                Employee {"John", "Doe"}};
    Employee_array[0].setEmployeeNumber(72);
    Employee_array[1].setEmployeeNumber(73);
    Employee_array[2].setEmployeeNumber(74);

    for (const auto &employee: Employee_array) {
        employee.display();
    }

    std::vector<Employee> Employee_vector {};
    Employee_vector.emplace_back("Grey", "Wallis");
    Employee_vector.emplace_back("Marc", "White");
    Employee_vector.emplace_back("John", "Doe");

    Employee_vector[0].setEmployeeNumber(72);
    Employee_vector[1].setEmployeeNumber(73);
    Employee_vector[2].setEmployeeNumber(74);
    for (const auto& employee: Employee_vector) {
        employee.display();
    }
    return 0;
}