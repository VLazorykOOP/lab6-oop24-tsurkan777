#include <iostream>
#include <string>
using namespace std;

// Клас працівник
class Employee {
public:
    string position;
    double salary;

    Employee(string pos, double sal) : position(pos), salary(sal) {}

    void showEmployee() {
        cout << "Посада: " << position << ", Зарплата: " << salary << endl;
    }
};

// Клас батько-сімейства
class Father {
public:
    int numberOfChildren;

    Father(int children) : numberOfChildren(children) {}

    void showFather() {
        cout << "Кількість дітей: " << numberOfChildren << endl;
    }
};

// Клас працівник-батько
class EmployeeFather : public Employee, public Father {
public:
    EmployeeFather(string pos, double sal, int children)
        : Employee(pos, sal), Father(children) {}

    void showAll() {
        showEmployee();
        showFather();
    }
};

int main() {
    system("chcp 65001");
    EmployeeFather ef("Інженер", 15000.0, 3);
    ef.showAll();

    return 0;
}
