//
// Created by liuye on 2023/12/7.
//
#include "Employee.hpp"
#include <iostream>
#include <format>

using namespace std;

namespace Records {
    Employee::Employee(const string& firstName,
        const string& lastName):
        m_firstName {firstName},
        m_lastName {lastName} {
    }
    void Employee::promote(const int raiseAmount) {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(const int demeritAmount) {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() {
         m_hired = true;
    }

    void Employee::fire() {
        m_hired = false;
    }

    void Employee::display() const {
        cout << format("Employee: {}, {}", getLastName(), getFirstName()) << endl;
        cout << "------------------" << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << format("Employee Number: {}", getEmployeeNumber()) << endl;
        cout << "------------------" << endl;
        cout << endl;
    }

    void Employee::setFirstName(const std::string& firstName) {
        m_firstName = firstName;
    }

    void Employee::setLastName(const std::string& lastName) {
        m_lastName = lastName;
    }

    void Employee::setEmployeeNumber(const int employeeNumber) {
        m_employeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const {
        return m_employeeNumber;
    }

    void Employee::setSalary(const int newSalary) {
        m_salary = newSalary;
    }

    int Employee::getSalary() const {
        return m_salary;
    }

    bool Employee::isHired() const {
        return m_hired;
    }

    const std::string& Employee::getFirstName() const {
        return m_firstName;
    }

    const std::string& Employee::getLastName() const {
        return m_lastName;
    }

}