#include <fstream>
#include <cctype>

int main() {
    #include <fstream>
#include <cctype>

int main() {
    setlocale(LC_ALL, "RUS");
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Не удалось открыть один или оба файла";
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (std::isalnum(ch) || ch == '\n') {
            outputFile.put(ch);
        }
    }

    return 0;
}

    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Не удалось открыть один или оба файла";
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (std::isalnum(ch) || ch == '\n') {
            outputFile.put(ch);
        }
    }

    return 0;
}
