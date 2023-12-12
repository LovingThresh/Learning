//
// Created by liuye on 2023/12/7.
//
#include <iostream>
#include <format>
#include <utility>

#include "Employee.hpp"



namespace HR {
    Employee::Employee(std::string  firstName, std::string  lastName):
        m_firstName {std::move(firstName)},
        m_lastName {std::move(lastName)} {
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

    void Employee::positon(const title position_title) {
        m_position = position_title;
    }

    void Employee::display() const {
        std::cout << format("Employee: {}, {}", getLastName(), getFirstName()) << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << (isHired() ? "Current Employee" : "Former Employee") << std::endl;
        std::cout << format("Employee Position: {}", getPositionTitle()) << std::endl;
        std::cout << std::format("Employee Number: {}", getEmployeeNumber()) << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << std::endl;
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

    std::string Employee::getPositionTitle() const {
        switch (m_position) {
            case title::Manager:
                return "Manager";
            case title::Senior_Engineer:
                return "Senior Engineer";
            case title::Enginerr:
                return "Engineer";
            default:
                return "Unknown";
        }
    }

    void Employee::setNickName(const std::string& nickName) {
        m_nickName = nickName;
    }

    std::optional<std::string> Employee::getNickName() const {
        return (m_nickName.empty() ? std::nullopt : m_nickName);
    }

    bool Employee::isHired() const {
        return m_hired;
    }

    bool Employee::isNicked() const {
        return (!m_nickName.empty());
    }

    const std::string& Employee::getFirstName() const {
        return m_firstName;
    }

    const std::string& Employee::getLastName() const {
        return m_lastName;
    }

}