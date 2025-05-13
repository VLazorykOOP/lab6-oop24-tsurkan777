
#include <iostream>

using namespace std;

// Це базовий клас A
class A {
public:
    int a; // Змінна з класу A
};

// Клас B успадковується від A (без віртуального успадкування)
class B : public A {
public:
    int b; // Змінна з класу B
};

// Клас C теж успадковується від A (без віртуального успадкування)
class C : public A {
public:
    int c; // Змінна з класу C
};

// Клас D1 успадковується від B та C (тут A буде двічі)
class D1 : public B, public C {
public:
    int d; // Змінна з класу D1
};

// Тепер спробуємо з віртуальним успадкуванням

// Клас VB успадковується від A віртуально
class VB : virtual public A {
public:
    int b; // Змінна з класу VB
};

// Клас VC теж успадковується від A віртуально
class VC : virtual public A {
public:
    int c; // Змінна з класу VC
};

// Клас D2 успадковується від VB і VC
class D2 : public VB, public VC {
public:
    int d; // Змінна з класу D2
};

int main() {
    system("chcp 65001");
    // Створюємо об'єкт класу D1 (без віртуального успадкування)
    D1 obj1;

    // Створюємо об'єкт класу D2 (з віртуальним успадкуванням)
    D2 obj2;

    // Виводимо розміри об'єктів
    cout << "Розмір obj1 (без віртуального успадкування): " << sizeof(obj1) << " байт" << endl;
    cout << "Розмір obj2 (з віртуальним успадкуванням): " << sizeof(obj2) << " байт" << endl;

    return 0;
}
