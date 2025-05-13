#include <iostream>
#include <cmath> // для sqrt()

using namespace std;

// Абстрактний клас Function
class Function {
public:
    // Віртуальна функція обчислення y за x
    virtual double calculate(double x) = 0; // чисто віртуальна
    virtual ~Function() {} // віртуальний деструктор
};

// Клас пряма: y = ax + b
class Line : public Function {
private:
    double a, b;
public:
    Line(double a_, double b_) : a(a_), b(b_) {}

    double calculate(double x) override {
        return a * x + b;
    }
};

// Клас еліпс: (x^2)/a^2 + (y^2)/b^2 = 1 => y = ±sqrt(b^2*(1 - x^2/a^2))
class Ellipse : public Function {
private:
    double a, b;
public:
    Ellipse(double a_, double b_) : a(a_), b(b_) {}

    double calculate(double x) override {
        if (abs(x) > a) {
            cout << "x поза межами еліпса. ";
            return NAN; // не число
        }
        return b * sqrt(1 - (x * x) / (a * a)); // тільки верхня половина
    }
};

// Клас гіпербола: (x^2)/a^2 - (y^2)/b^2 = 1 => y = ±sqrt((x^2/a^2 - 1) * b^2)
class Hyperbola : public Function {
private:
    double a, b;
public:
    Hyperbola(double a_, double b_) : a(a_), b(b_) {}

    double calculate(double x) override {
        if (abs(x) < a) {
            cout << "x у забороненій зоні (|x| < a). ";
            return NAN;
        }
        return b * sqrt((x * x) / (a * a) - 1); // тільки верхня гілка
    }
};

int main() {
    system("chcp 65001");
    Function* f1 = new Line(2.0, 3.0);        // y = 2x + 3
    Function* f2 = new Ellipse(5.0, 3.0);     // еліпс з a=5, b=3
    Function* f3 = new Hyperbola(2.0, 4.0);   // гіпербола з a=2, b=4

    double x;

    cout << "Введіть x: ";
    cin >> x;

    cout << "Пряма: y = " << f1->calculate(x) << endl;
    cout << "Еліпс: y = " << f2->calculate(x) << endl;
    cout << "Гіпербола: y = " << f3->calculate(x) << endl;

    // Звільнення пам’яті
    delete f1;
    delete f2;
    delete f3;

    return 0;
}

