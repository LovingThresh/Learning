//
// Created by liuye on 2023/12/8.
//
#include <iostream>
#include <stdexcept>
#include <format>
#include <string>
#include "Database.hpp"


using namespace std;
using namespace HR;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);

int main() {
    Database employeeDB;
    bool done {false};
    while (!done) {
        switch (displayMenu()) {
            case 0:
                done = true;
                break;
            case 1:
                doHire(employeeDB);
                break;
            case 2:
                doFire(employeeDB);
                break;
            case 3:
                doPromote(employeeDB);
            case 4:
                employeeDB.displayAll();
                break;
            case 5:
                employeeDB.displayCurrent();
                break;
            case 6:
                employeeDB.displayFormer();
                break;
            default:
                cerr << "Unknown command." << endl;
                break;
        }
    }
}

int displayMenu() {
    int selection;
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) List all employees" << endl;
    cout << "5) List all current employees" << endl;
    cout << "6) List all former employees" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> selection;
    return selection;
}

void doHire(Database& db) {
    string firstName;
    string lastName;

    cout << "First name? ";
    cin >> firstName;

    cout << "Last name? ";
    cin >> lastName;

    const auto& employee {db.addEmployee(firstName, lastName)};
    cout << format("Employee {} {} with Employee number {} was hired.",
        firstName, lastName, employee.getEmployeeNumber()) << endl;
}

void doFire(Database& db) {
    int employeeNumber;
    cout << "Employee number? ";
    cin >> employeeNumber;
    try {
        auto& emp { db.getEmployee(employeeNumber) };
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } catch (const std::logic_error& exception) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void doPromote(Database& db) {
    int employeeNumber;
    cout << "Employee number?" << endl;
    cin >> employeeNumber;

    int raiseAmount;
    cout << "How much of a raise?" << endl;
    cin >> raiseAmount;

    try {
        auto& emp {db.getEmployee(employeeNumber)};
        emp.promote();
    } catch (const std::logic_error& exception) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}
