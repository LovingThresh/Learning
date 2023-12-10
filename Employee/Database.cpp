//
// Created by liuye on 2023/12/8.
//

#include "Database.hpp"
#include <stdexcept>

using namespace std;

namespace Records{
    Employee& Database::addEmployee(const std::string&firstName, const std::string&lastname) {
        Employee theEmployee {firstName, lastname};
        theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
        theEmployee.hire();
        m_employees.push_back(theEmployee);
        return m_employees.back();
    }
    Employee& Database::getEmployee(const int employeeNumber) {
        for (auto& employee : m_employees) {
            if (employee.getEmployeeNumber() == employeeNumber) {
                return employee;
            }
        }
        throw logic_error("No employee found.");
    }

    Employee& Database::getEmployee(const std::string& firstName, const std::string& lastname) {
        for (auto& employee : m_employees) {
            if ((employee.getFirstName() == firstName) && (employee.getLastName() == lastname)) {
                return employee;
            }
        }
        throw logic_error("No employee found.");
    }

    void Database::displayAll() const {
        for (auto& employee : m_employees) {
            employee.display();
        }
    }

    void Database::displayCurrent() const {
        for (auto& employee : m_employees) {
            if (employee.isHired()) { employee.display();}
        }
    }


    void Database::displayFormer() const {
        for (auto& employee : m_employees) {
            if (! employee.isHired()) {employee.display();}
        }
    }
}









