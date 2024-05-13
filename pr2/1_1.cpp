#include <fstream>
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    std::ifstream file("a.txt");
    if (!file) {
        std::cerr << "Не удалось открыть файл";
        return 1;
    }

    double num;
    int zeroCount = 0;
    double positiveSum = 0.0;

    while (file >> num) {
        if (num == 0.0) {
            ++zeroCount;
        }
        else if (num > 0.0) {
            positiveSum += num;
        }
    }

    std::cout << "Количество нулевых элементов: " << zeroCount << '\n';
    std::cout << "Сумма положительных элементов: " << positiveSum << '\n';

    return 0;
}
f