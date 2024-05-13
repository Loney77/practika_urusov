#include <fstream>
#include <iostream>

int countNegative(std::ifstream& file) {
    double num;
    int negativeCount = 0;

    while (file >> num) {
        if (num < 0.0) {
            ++negativeCount;
        }
    }

    return negativeCount;
}

int main() {
    setlocale(LC_ALL, "RUS");
    
    std::ifstream file1("a1.txt");
    std::ifstream file2("a2.txt");

    if (!file1 || !file2) {
        std::cerr << "Не удалось открыть один или оба файла";
        return 1;
    }

    int negativeCount1 = countNegative(file1);
    int negativeCount2 = countNegative(file2);

    if (negativeCount1 > negativeCount2) {
        std::cout << "В файле a1.txt больше отрицательных элементов\n";
    }
    else if (negativeCount2 > negativeCount1) {
        std::cout << "В файле a2.txt больше отрицательных элементов\n";
    }
    else {
        std::cout << "Количество отрицательных элементов в обоих файлах одинаково\n";
    }

    return 0;
}
