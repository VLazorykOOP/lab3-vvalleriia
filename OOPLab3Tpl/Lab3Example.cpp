#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include <complex>
#include <fstream>

#pragma once
void exercise1();
void exercise2();
int mainExample4();

/*Створити клас типу – круг ( поля : радіус, колір). У класі визначити
o конструктори ( не менше двох);
o функції-члени обчислення площі круга, довжини кола;
o функції-члени встановлення значення радіусу та кольору, функції встановлення
полів класу повинні перевіряти коректність параметрів, що задаються;
o функції-члени що повертають значення полів;
o функцію друку.
Написати програму тестування всіх можливостей цього класу.*/

class Circle {
private:
    double radius;
    string color;
public:
    Circle() {
        radius = 1.0;
        color = "red";
    }
    Circle(double r) {
        radius = r;
        color = "red";
    }
    Circle(double r, string c) {
        radius = r;
        color = c;
    }
    double getRadius() {
        return radius;
    }
    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        }
        else {
            cout << "Invalid radius value" << endl;
        }
    }
    string getColor() {
        return color;
    }
    void setColor(string c) {
        color = c;
    }
    double getArea() {
        return M_PI * pow(radius, 2);
    }
    double getPerimeter() {
        return 2 * M_PI * radius;
    }
    void print() {
        cout << "Circle - radius: " << radius << ", color: " << color << endl;
    }
};

int main1() {
    Circle c1; // create a circle with default values
    Circle c2(3.0); // create a circle with radius 3.0 and default color
    Circle c3(2.5, "blue"); // create a circle with radius 2.5 and color blue
    cout << "Circle 1 - area: " << c1.getArea() << ", perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle 2 - area: " << c2.getArea() << ", perimeter: " << c2.getPerimeter() << endl;
    cout << "Circle 3 - area: " << c3.getArea() << ", perimeter: " << c3.getPerimeter() << endl;
    c1.print();
    c2.print();
    c3.print();
    c1.setRadius(2.0);
    c1.setColor("green");
    cout << "Circle 1 - radius: " << c1.getRadius() << ", color: " << c1.getColor() << endl;
    c1.print();
    return 0;
}
void ShowExercise1Menu() {
    cout << "1. Enter from console" << endl;
    cout << "2. Read from txt" << endl;
    cout << "3. Default radius " << endl;
}
void exercise1() {
    bool isSelected = false;
    Circle d;
    ifstream fin("Circle.txt");
    int radius;
    while (!isSelected) {
        system("cls");
        ShowExercise1Menu();
        int ch;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter radius of circle:";
            cin >> radius;
            d.setRadius(radius);
            d.print();
            isSelected = true;
            break;
        case 2:
            fin >> radius;
            d.setRadius(radius);
            d.print();
            isSelected = true;
            break;
        case 3:
            d.print();
            isSelected = true;
            break;
        default:
            break;
        }
    }
}

enum STATE { OK, BAD_INIT, BAD_DIV };



/*Створити тип даних - клас комплексне число, який має поля re та im типу float і поле
змінну стану. У класі визначити

o конструктор без параметрів(інінціалізує поля в нуль);
o конструктор з одним параметром типу float (інінціалізує поля re та im
значенням параметру);
o конструктор з одним параметром вказівник на тип (інінціалізує поля re та im
значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити
код помилки);
o деструктор із виведенням інформації про стан вектора;
o визначити функцію, яка присвоює полю re та im деяке значення (параметр за
замовчуванням);
o функцію яка одержує деякий елемент з полів re та im;
o конструктор копій та операцію присвоєння; // !!!
o визначити функції друку, додавання, віднімання, множення та ділення які
здійснюють ці арифметичні операції з даними цього класу;
o функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не
виконувати);
o норми комплексного числа;
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.

У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в
конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу.
Написати програму тестування всіх можливостей цього класу.*/

template<typename T>
class Complex {
private:
    T re;
    T im;
    int state;

public:
    static int count;

    Complex() {
        re = 0.0;
        im = 0.0;
        state = 0;
        count++;
    }

    Complex(T real) {
        re = real;
        im = 0.0;
        state = 0;
        count++;
    }

    Complex(T* arr) {
        if (arr == nullptr) {
            state = 1;
        }
        else {
            re = arr[0];
            im = arr[1];
            state = 0;
        }
        count++;
    }

    ~Complex() {
    }

    void setValue(T real = 0.0, T imag = 0.0) {
        re = real;
        im = imag;
    }

    T getReal() const {
        return re;
    }

    T getImag() const {
        return im;
    }

    Complex(const Complex& other) {
        re = other.re;
        im = other.im;
        state = other.state;
        count++;
    }

    Complex& operator=(const Complex& other) {
        if (this != &other) {
            re = other.re;
            im = other.im;
            state = other.state;
        }
        return *this;
    }

    void print() const {
        if (state == 1) {
            std::cout << "Error: null pointer passed." << std::endl;
        }
        else {
            std::cout << re << " + " << im << "i" << std::endl;
        }
    }

    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator*(const Complex& other) const {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    Complex operator/(const Complex& other) const {
        if (other.re == 0 && other.im == 0) {
            std::cout << "Error: division by zero." << std::endl;
            return Complex(0.0, 0.0);
        }
        T denominator = other.re * other.re + other.im * other.im;
        T numerator_re = re * other.re + im * other.im;
        T numerator_im = im * other.re - re * other.im;
        return Complex(numerator_re / denominator, numerator_im / denominator);
    }

    T norm() const {
        return std::sqrt(re * re + im * im);
    }

    bool operator>(const Complex& other) const {
        return norm() > other.norm();
    }

    bool operator<(const Complex& other) const {
        return norm() < other.norm();
    }

    bool operator==(const Complex& other) const {
        return re == other.re && im == other.im;
    }
};
template<typename T>
int Complex<T>::count = 0;

void exercise2() {
    // Create objects using different constructors
    ComplexNumber c1; // default constructor
    ComplexNumber c2(2.0); // constructor with one float parameter
    float arr[2] = { 3.0, 4.0 };
    ComplexNumber c3(arr); // constructor with pointer parameter

    // Print the values of the created objects
    cout << "c1: ";
    c1.print();
    cout << "c2: ";
    c2.print();
    cout << "c3: ";
    c3.print();

    return ;
}


void ShowTaskMenu() {
    cout << "Exersices" << endl;
    cout << "1. Task 1" << endl;
    cout << "2. Task 2" << endl;
}

int main() {
    bool isSelected = false;
    while (!isSelected) {
        system("cls");
        ShowTaskMenu();
        int ch;
        cin >> ch;
        switch (ch) {
        case 1:
           exercise1();
            isSelected = true;
            break;
        case 2:
            exercise2();
            isSelected = true;
            break;
        case 3:
            isSelected = true;
            break;
        default:
            break;
        }
    }
    return 0;
}
