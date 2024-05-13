#include <fstream>
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    std::ifstream inputFile("f.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Не удалось открыть файл";
        return 1;
    }

    double number;
    double sum = 0.0;
    while (inputFile >> number) {
        sum += number;
    }

    outputFile << "Сумма компонент файла: " << sum << std::endl;

    return 0;
}
