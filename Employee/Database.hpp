//
// Created by liuye on 2023/12/8.
//

#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include <memory>
#include "Employee.hpp"

namespace HR {
    constexpr int FirstEmployeeNumber {1000};
    class Database {
    public:
        [[nodiscard]] Employee& addEmployee(const std::string& firstName, const std::string& lastname);
        [[nodiscard]] Employee& getEmployee(int employeeNumber) const ;
        [[nodiscard]] Employee& getEmployee(const std::string& firstName, const std::string& lastname) const;
        void displayAll() const ;
        void displayCurrent() const ;
        void displayFormer() const ;

    private:
        mutable std::vector<Employee> m_employees;
        int m_nextEmployeeNumber {FirstEmployeeNumber};
    };
}



#endif //DATABASE_H
