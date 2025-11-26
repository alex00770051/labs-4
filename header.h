#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include <iostream>

class RightTriangle {
private:
    double a; // первый катет
    double b; // второй катет

    // Проверка корректности треугольника
    bool isValid() const;

public:
    // Конструкторы
    RightTriangle();
    RightTriangle(double a_val, double b_val);
    RightTriangle(const RightTriangle& other);

    // Геттеры
    double getA() const;
    double getB() const;

    // Сеттеры с проверкой корректности
    void setA(double newA);
    void setB(double newB);

    // Основной метод - вычисление площади треугольника
    double calculateArea() const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const RightTriangle& triangle);

    // Унарные операции
    RightTriangle& operator++();    // Префиксный ++
    RightTriangle operator++(int);  // Постфиксный ++
    RightTriangle& operator--();    // Префиксный --
    RightTriangle operator--(int);  // Постфиксный --

    // Операции приведения типа
    explicit operator double() const; // Явное приведение к double
    operator bool() const;           // Неявное приведение к bool

    // Бинарные операции
    bool operator<=(const RightTriangle& other) const;
    bool operator>=(const RightTriangle& other) const;
};

// Функция для безопасного ввода
double safeInput(const std::string& prompt);

#endif
