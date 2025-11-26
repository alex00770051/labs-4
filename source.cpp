#include "header.h"
#include <limits>
#include <cmath>

// Конструктор по умолчанию
RightTriangle::RightTriangle() : a(1.0), b(1.0) {}

// Конструктор с параметрами
RightTriangle::RightTriangle(double a_val, double b_val) : a(a_val), b(b_val) {
    if (!isValid()) {
        a = 1.0;
        b = 1.0;
        std::cout << "Некорректные данные! Установлены значения по умолчанию (1.0, 1.0)" << std::endl;
    }
}

// Конструктор копирования
RightTriangle::RightTriangle(const RightTriangle& other) : a(other.a), b(other.b) {}

// Геттеры
double RightTriangle::getA() const { return a; }
double RightTriangle::getB() const { return b; }

// Сеттеры с проверкой корректности
void RightTriangle::setA(double newA) {
    if (newA > 0) {
        a = newA;
    }
    else {
        std::cout << "Ошибка: катет должен быть положительным числом!" << std::endl;
    }
}

void RightTriangle::setB(double newB) {
    if (newB > 0) {
        b = newB;
    }
    else {
        std::cout << "Ошибка: катет должен быть положительным числом!" << std::endl;
    }
}

// Проверка корректности треугольника
bool RightTriangle::isValid() const {
    return a > 0 && b > 0;
}

// Основной метод - вычисление площади треугольника
double RightTriangle::calculateArea() const {
    return (a * b) / 2.0;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const RightTriangle& triangle) {
    os << "a=" << triangle.a << ", b=" << triangle.b << ", площадь=" << triangle.calculateArea();
    return os;
}

// Унарные операции
RightTriangle& RightTriangle::operator++() {
    a *= 2;
    b *= 2;
    return *this;
}

RightTriangle RightTriangle::operator++(int) {
    RightTriangle temp = *this;
    a *= 2;
    b *= 2;
    return temp;
}

RightTriangle& RightTriangle::operator--() {
    a /= 2;
    b /= 2;
    return *this;
}

RightTriangle RightTriangle::operator--(int) {
    RightTriangle temp = *this;
    a /= 2;
    b /= 2;
    return temp;
}

// Операции приведения типа
RightTriangle::operator double() const {
    return isValid() ? calculateArea() : -1.0;
}

RightTriangle::operator bool() const {
    return isValid();
}

// Бинарные операции
bool RightTriangle::operator<=(const RightTriangle& other) const {
    return calculateArea() <= other.calculateArea();
}

bool RightTriangle::operator>=(const RightTriangle& other) const {
    return calculateArea() >= other.calculateArea();
}

// Функция для безопасного ввода числа
double safeInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Введите положительное число: ";
        }
        else {
            break;
        }
    }
    return value;
}
