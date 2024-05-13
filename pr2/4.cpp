#include <fstream>
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    std::ifstream inputFile("numbers.txt");

    if (!inputFile) {
        std::cerr << "Не удалось открыть файл";
        return 1;
    }

    int number, sum = 0;
    int position = 0;

    while (inputFile >> number) {
        if (position % 2 == 0) {
            sum += number;
        }
        position++;
    }

    std::cout << "Сумма чисел на четных позициях: " << sum << std::endl;

    return 0;
}
