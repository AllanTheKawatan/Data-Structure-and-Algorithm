#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // for system("CLS")
#include <limits>  // for numeric_limits

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

class SalaryManagement {
private:
    vector<Employee> employees;
    int nextId;

public:
    SalaryManagement() : nextId(1) {}

    void addEmployee() {
        char choice;
        do {
            Employee emp;
            emp.id = nextId++;
            cout << "Enter employee name: ";
            while (!(cin >> emp.name) || emp.name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
                cout << "Invalid input. Please enter a valid name: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter employee salary (PHP): ";
            while (!(cin >> emp.salary)) {
                cout << "Invalid input. Please enter a valid salary: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            employees.push_back(emp);
            cout << "Employee added successfully!\n";

            cout << "Do you want to add another employee? (y/n): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        } while (choice == 'y' || choice == 'Y');
    }

    void viewEmployees() {
        cout << "ID\tName\tSalary\n";
        for (const auto& emp : employees) {
            cout << emp.id << "\t" << emp.name << "\tPHP" << emp.salary << "\n";
        }
    }

    void updateEmployee() {
        int id;
        cout << "===Enter employee ID to update: ==== ";
        cin >> id;
        for (auto& emp : employees) {
            if (emp.id == id) {
                cout << "Enter new name: ";
                while (!(cin >> emp.name) || emp.name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
                    cout << "Invalid input. Please enter a valid name: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter new salary: ";
                while (!(cin >> emp.salary)) {
                    cout << "Invalid input. Please enter a valid salary: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Employee updated successfully!\n";
                return;
            }
        }
        cout << "Employee not found!\n";
        viewEmployees(); // Display all employees
    }

    void deleteEmployee() {
        int id;
        cout << "Enter employee ID to delete: ";
        cin >> id;
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->id == id) {
                employees.erase(it);
                cout << "Employee deleted successfully!\n";
                return;
            }
        }
        cout << "Employee not found!\n";
    }
};

void clearScreen() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

void displayMenu() {
    cout << "<======================================>\n";
    cout << " Salary of Employeee Management System\n";
    cout << "<======================================>\n";
    cout << "1. Add Employee\n";
    cout << "2. View Employees\n";
    cout << "3. Update Employee\n";
    cout << "4. Delete Employee\n";
    cout << "5. Exit\n";
    cout << "<======================================>\n";
}

int main() {
    SalaryManagement sm;
    int choice;

    while (true) {
        clearScreen();
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        clearScreen();
        switch (choice) {
            case 1:
                sm.addEmployee();
                break;
            case 2:
                sm.viewEmployees();
                break;
            case 3:
                sm.updateEmployee();
                break;
            case 4:
                sm.deleteEmployee();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
}
