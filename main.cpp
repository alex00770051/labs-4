#include "header.h"
#include <iostream>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "МЕНЮ ДЕМОНСТРАЦИИ КЛАССА RIGHTTRIANGLE" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "1. Создать новый треугольник" << std::endl;
    std::cout << "2. Показать текущие треугольники" << std::endl;
    std::cout << "3. Операция ++ (увеличить в 2 раза)" << std::endl;
    std::cout << "4. Операция -- (уменьшить в 2 раза)" << std::endl;
    std::cout << "5. Явное приведение к double (площадь)" << std::endl;
    std::cout << "6. Неявное приведение к bool (существование)" << std::endl;
    std::cout << "7. Сравнение треугольников (<= и >=)" << std::endl;
    std::cout << "8. Тестирование всех конструкторов" << std::endl;
    std::cout << "9. Тестирование геттеров и сеттеров" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Выберите действие: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getMenuChoice() {
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 0 || choice > 9) {
            std::cout << "Ошибка! Введите число от 0 до 9: ";
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            return choice;
        }
    }
}

void createTriangle(RightTriangle& triangle) {
    std::cout << "\n--- СОЗДАНИЕ ТРЕУГОЛЬНИКА ---" << std::endl;
    double a = safeInput("Введите катет a: ");
    double b = safeInput("Введите катет b: ");
    triangle = RightTriangle(a, b);
    std::cout << "Создан: " << triangle << std::endl;
}

void showTriangles(const RightTriangle& t1, const RightTriangle& t2) {
    std::cout << "\n--- ТЕКУЩИЕ ТРЕУГОЛЬНИКИ ---" << std::endl;
    std::cout << "Треугольник 1: " << t1 << std::endl;
    std::cout << "Треугольник 2: " << t2 << std::endl;
}

void demonstrateIncrement(RightTriangle& triangle) {
    std::cout << "\n--- ОПЕРАЦИЯ ++ (УВЕЛИЧЕНИЕ В 2 РАЗА) ---" << std::endl;

    // Сохраняем исходное состояние
    RightTriangle original = triangle;

    // Демонстрация префиксного ++
    std::cout << "Исходный треугольник: " << original << std::endl;

    RightTriangle prefix = original;
    std::cout << "Префиксный ++: ";
    ++prefix;
    std::cout << prefix << std::endl;

    // Демонстрация постфиксного ++
    RightTriangle postfix = original;
    std::cout << "Постфиксный ++: ";
    RightTriangle temp = postfix++;
    std::cout << "После операции: " << postfix << std::endl;
    std::cout << "Возвращенное значение: " << temp << std::endl;

    // Применяем изменения
    triangle = prefix;
}

void demonstrateDecrement(RightTriangle& triangle) {
    std::cout << "\n--- ОПЕРАЦИЯ -- (УМЕНЬШЕНИЕ В 2 РАЗА) ---" << std::endl;

    // Сохраняем исходное состояние
    RightTriangle original = triangle;

    // Демонстрация префиксного --
    std::cout << "Исходный треугольник: " << original << std::endl;

    RightTriangle prefix = original;
    std::cout << "Префиксный --: ";
    --prefix;
    std::cout << prefix << std::endl;

    // Демонстрация постфиксного --
    RightTriangle postfix = original;
    std::cout << "Постфиксный --: ";
    RightTriangle temp = postfix--;
    std::cout << "После операции: " << postfix << std::endl;
    std::cout << "Возвращенное значение: " << temp << std::endl;

    // Применяем изменения
    triangle = prefix;
}

void demonstrateDoubleConversion(const RightTriangle& t1, const RightTriangle& t2) {
    std::cout << "\n--- ЯВНОЕ ПРИВЕДЕНИЕ К DOUBLE (ПЛОЩАДЬ) ---" << std::endl;
    std::cout << "Треугольник 1: " << t1 << std::endl;
    std::cout << "static_cast<double>(t1) = " << static_cast<double>(t1) << std::endl;

    std::cout << "Треугольник 2: " << t2 << std::endl;
    std::cout << "static_cast<double>(t2) = " << static_cast<double>(t2) << std::endl;

    // Демонстрация с некорректным треугольником
    RightTriangle invalid(-1, -1);
    std::cout << "Некорректный треугольник: " << invalid << std::endl;
    std::cout << "static_cast<double>(invalid) = " << static_cast<double>(invalid) << std::endl;
}

void demonstrateBoolConversion(const RightTriangle& t1, const RightTriangle& t2) {
    std::cout << "\n--- НЕЯВНОЕ ПРИВЕДЕНИЕ К BOOL (СУЩЕСТВОВАНИЕ) ---" << std::endl;
    std::cout << "Треугольник 1: " << t1 << std::endl;
    std::cout << "bool(t1) = " << (t1 ? "true" : "false") << std::endl;

    std::cout << "Треугольник 2: " << t2 << std::endl;
    std::cout << "bool(t2) = " << (t2 ? "true" : "false") << std::endl;

    // Использование в условиях
    std::cout << "\nИспользование в условиях:" << std::endl;
    if (t1) {
        std::cout << "Треугольник 1 существует и может использоваться" << std::endl;
    }
    if (t2) {
        std::cout << "Треугольник 2 существует и может использоваться" << std::endl;
    }
}

void demonstrateComparison(const RightTriangle& t1, const RightTriangle& t2) {
    std::cout << "\n--- СРАВНЕНИЕ ТРЕУГОЛЬНИКОВ ---" << std::endl;
    std::cout << "Треугольник 1: " << t1 << std::endl;
    std::cout << "Треугольник 2: " << t2 << std::endl;

    std::cout << "\nРезультаты сравнения:" << std::endl;
    std::cout << "t1 <= t2: " << (t1 <= t2 ? "true" : "false") << std::endl;
    std::cout << "t1 >= t2: " << (t1 >= t2 ? "true" : "false") << std::endl;
    std::cout << "t2 <= t1: " << (t2 <= t1 ? "true" : "false") << std::endl;
    std::cout << "t2 >= t1: " << (t2 >= t1 ? "true" : "false") << std::endl;
}

void demonstrateConstructors() {
    std::cout << "\n--- ТЕСТИРОВАНИЕ КОНСТРУКТОРОВ ---" << std::endl;

    std::cout << "1. Конструктор по умолчанию:" << std::endl;
    RightTriangle t1;
    std::cout << "RightTriangle t1; -> " << t1 << std::endl;

    std::cout << "\n2. Конструктор с параметрами:" << std::endl;
    RightTriangle t2(5.0, 12.0);
    std::cout << "RightTriangle t2(5.0, 12.0); -> " << t2 << std::endl;

    std::cout << "\n3. Конструктор копирования:" << std::endl;
    RightTriangle t3(t2);
    std::cout << "RightTriangle t3(t2); -> " << t3 << std::endl;

    std::cout << "\n4. Конструктор с некорректными данными:" << std::endl;
    RightTriangle t4(-1.0, 0.0);
    std::cout << "RightTriangle t4(-1.0, 0.0); -> " << t4 << std::endl;
}

void demonstrateGettersSetters() {
    std::cout << "\n--- ТЕСТИРОВАНИЕ ГЕТТЕРОВ И СЕТТЕРОВ ---" << std::endl;

    RightTriangle triangle(3, 4);
    std::cout << "Исходный треугольник: " << triangle << std::endl;

    std::cout << "\nИспользование геттеров:" << std::endl;
    std::cout << "triangle.getA() = " << triangle.getA() << std::endl;
    std::cout << "triangle.getB() = " << triangle.getB() << std::endl;

    std::cout << "\nИспользование сеттеров (корректные данные):" << std::endl;
    triangle.setA(6.0);
    triangle.setB(8.0);
    std::cout << "После setA(6.0) и setB(8.0): " << triangle << std::endl;

    std::cout << "\nИспользование сеттеров (некорректные данные):" << std::endl;
    triangle.setA(-5.0);
    triangle.setB(0.0);
    std::cout << "После попытки setA(-5.0) и setB(0.0): " << triangle << std::endl;
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    // Инициализация треугольников по умолчанию
    RightTriangle triangle1(3.0, 4.0);
    RightTriangle triangle2(5.0, 12.0);

    std::cout << "ДЕМОНСТРАЦИЯ КЛАССА RIGHTTRIANGLE" << std::endl;
    std::cout << "Исходные треугольники:" << std::endl;
    std::cout << "Треугольник 1: " << triangle1 << std::endl;
    std::cout << "Треугольник 2: " << triangle2 << std::endl;

    int choice;
    do {
        printMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 1: {
            std::cout << "\nВыберите треугольник для изменения (1 или 2): ";
            int tChoice;
            std::cin >> tChoice;
            clearInputBuffer();
            if (tChoice == 1) {
                createTriangle(triangle1);
            }
            else if (tChoice == 2) {
                createTriangle(triangle2);
            }
            else {
                std::cout << "Неверный выбор!" << std::endl;
            }
            break;
        }
        case 2:
            showTriangles(triangle1, triangle2);
            break;
        case 3: {
            std::cout << "\nВыберите треугольник (1 или 2): ";
            int tChoice;
            std::cin >> tChoice;
            clearInputBuffer();
            if (tChoice == 1) demonstrateIncrement(triangle1);
            else if (tChoice == 2) demonstrateIncrement(triangle2);
            else std::cout << "Неверный выбор!" << std::endl;
            break;
        }
        case 4: {
            std::cout << "\nВыберите треугольник (1 или 2): ";
            int tChoice;
            std::cin >> tChoice;
            clearInputBuffer();
            if (tChoice == 1) demonstrateDecrement(triangle1);
            else if (tChoice == 2) demonstrateDecrement(triangle2);
            else std::cout << "Неверный выбор!" << std::endl;
            break;
        }
        case 5:
            demonstrateDoubleConversion(triangle1, triangle2);
            break;
        case 6:
            demonstrateBoolConversion(triangle1, triangle2);
            break;
        case 7:
            demonstrateComparison(triangle1, triangle2);
            break;
        case 8:
            demonstrateConstructors();
            break;
        case 9:
            demonstrateGettersSetters();
            break;
        case 0:
            std::cout << "\nВыход из программы..." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }

        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.get();
        }

    } while (choice != 0);

    return 0;
}
