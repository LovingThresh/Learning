//
// Created by liuye on 2023/12/7.
//

export module employee;
import <string>;

namespace Records {
    constexpr int DefaultStartingSalary {30'000};
    export constexpr int DefaultRaiseAndDeneritAmount {1'000};
    export class Employee {
    public:
        Employee(const std::string& firstName,
            const std::string& lastName);
        void promote(int raiseAmount = DefaultRaiseAndDeneritAmount);
        void demote(int demeritAmount = DefaultRaiseAndDeneritAmount);
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

        void setSalary(int newSalary);
        [[nodiscard]] int getSalary() const;

        [[nodiscard]] bool isHred() const;

    private:
        std::string m_firstName;
        std::string m_lastName;
        int m_employeeNumber { -1 };
        int m_salary {DefaultStartingSalary};
        bool m_hired { false };
    };
}
