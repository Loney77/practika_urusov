#include <iostream>
#include <string>
#include <cmath>

class ComplexNumber {
    
public:
    // Конструктор по умолчанию
    ComplexNumber() : a1(0), b1(0) {}

    // Конструктор перезагрузки с параметрами
    ComplexNumber(double a, double b) : a1(a), b1(b) {}

    // Деструктор для освобождения памяти
    ~ComplexNumber() {
        std::cout << "Объект уничтожен" << std::endl;
    }

    // Функция обработки данных (1) - вычисление модуля комплексного числа
    double processData1() {
        return std::sqrt(a1 * a1 + b1 * b1);
    }

    // Функция обработки данных (2) - нахождение комплексного числа, обратного заданному
    ComplexNumber processData2() const {
        double denominator = a1 * a1 + b1 * b1;
        double newA = a1 / denominator;
        double newB = -b1 / denominator;
        return ComplexNumber(newA, newB);
    }

    // Функция формирования строки информации об объекте
    std::string getInfo() {
        return "Действительная часть: " + std::to_string(a1) + ", Мнимая часть: " + std::to_string(b1);
    }

private:
    double a1;
    double b1;
};

int main() {
    setlocale(LC_ALL, "RUS");
    // Создаем объекты со значениями-константами
    ComplexNumber constComplexNumber(3, 4);
    std::cout << "Константа: " << constComplexNumber.getInfo() << std::endl;
    std::cout << "Модуль комплексного числа: " << constComplexNumber.processData1() << std::endl;
    std::cout << "Обратное комплексное число: " << constComplexNumber.processData2().getInfo() << std::endl;

    // Создаем объекты с введенными значениями полей объекта из компонентов
    double a, b;
    std::cout << "Введите действительную часть комплексного числа: ";
    std::cin >> a;
    std::cout << "Введите мнимую часть комплексного числа: ";
    std::cin >> b;
    ComplexNumber userComplexNumber(a, b);
    std::cout << "Пользовательский ввод: " << userComplexNumber.getInfo() << std::endl;
    std::cout << "Модуль комплексного числа: " << userComplexNumber.processData1() << std::endl;
    std::cout << "Обратное комплексное число: " << userComplexNumber.processData2().getInfo() << std::endl;

    return 0;
}