#include <fstream>
#include <iostream>
#include <vector>

int main() {
    setlocale(LC_ALL, "RUS");
    std::vector<std::vector<int>> array = {
        // Заполните массив
    };

    std::ofstream outputFile("array.bin", std::ios::binary);
    for (const auto& row : array) {
        for (const auto& element : row) {
            outputFile.write((char*)&element, sizeof(element));
        }
    }
    outputFile.close();

    std::cout << "Массив до изменения:\n";
    for (const auto& row : array) {
        for (const auto& element : row) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }

    std::ifstream inputFile("array.bin", std::ios::binary);
    std::vector<std::vector<int>> newArray(5, std::vector<int>(5));
    for (auto& row : newArray) {
        for (auto& element : row) {
            inputFile.read((char*)&element, sizeof(element));
            element *= 2;
        }
    }

    std::cout << "Массив после изменения:\n";
    for (const auto& row : newArray) {
        for (const auto& element : row) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
