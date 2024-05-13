#include <iostream>
#include <string>

class Trapezoid {
    setlocale(LC_ALL, "RUS");
private:
    int lowerBase;
    int upperBase;

public:
    // Конструктор для инициализации объекта
    Trapezoid(int lower, int upper) : lowerBase(lower), upperBase(upper) {}

    // Функция формирования строки с информацией об объекте
    std::string getInfo() {
        return "Нижнее основание трапеции: " + std::to_string(lowerBase) + ", Верхнее основание трапеции: " + std::to_string(upperBase);
    }

    // Функция обработки значений полей
    double processFields() {
        return (lowerBase + upperBase) / 2.0;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    // Создание объекта класса Trapezoid
    Trapezoid trapezoid(10, 20);

    // Вывод информации об объекте
    std::cout << trapezoid.getInfo() << std::endl;

    // Вывод результата обработки полей
    std::cout << "Полусумма оснований трапеции: " << trapezoid.processFields() << std::endl;

    return 0;
}
