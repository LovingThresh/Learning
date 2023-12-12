//
// Created by liuye on 2023/12/7.
//
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <optional>

namespace HR {
    constexpr int DefaultStartingSalary {30'000};
    constexpr int DefaultRaiseAndDeneritAmount {1'000};
    enum class title {Manager, Senior_Engineer, Enginerr};
    constexpr title DefaultPosition {title::Enginerr};

    class Employee {
    public:
        Employee(std::string  firstName, std::string  lastName);
        void promote(int raiseAmount = DefaultRaiseAndDeneritAmount);
        void demote(int demeritAmount = DefaultRaiseAndDeneritAmount);
        void positon(title position_title = DefaultPosition);
        void hire();
        void fire();
        void display() const;

        // Getters and setters
        // Tab v -> &
        void setFirstName(const std::string& firstName);
        [[nodiscard]] const std::string& getFirstName() const;

        void setLastName(const std::string& lastName);
        [[nodiscard]] const std::string& getLastName() const;

        void setEmployeeNumber(int employeeNumber);
        [[nodiscard]] int getEmployeeNumber() const;

        void setNickName(const std::string &nickName);
        [[nodiscard]] std::optional<std::string> getNickName() const;

        void setSalary(int newSalary);
        [[nodiscard]] int getSalary() const;
        [[nodiscard]] std::string getPositionTitle() const;
        [[nodiscard]] bool isHired() const;
        [[nodiscard]] bool isNicked() const;

    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_nickName;
        int m_employeeNumber { -1 };
        int m_salary {DefaultStartingSalary};
        bool m_hired { false };
        title m_position {title::Enginerr};
    };
}
#endif
