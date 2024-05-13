#include <fstream>
#include <iostream>
#include <vector>
#include <string>

struct Worker {
    std::string surname;
    int age;
    std::string education;
    std::string position;
    std::string gender;
};

int main() {
    setlocale(LC_ALL, "RUS");
    std::vector<Worker> workers = {
        // Заполните информацию о работниках
    };

    std::ofstream outputFile("workers.bin", std::ios::binary);
    for (const auto& worker : workers) {
        outputFile.write((char*)&worker, sizeof(worker));
    }
    outputFile.close();

    std::ifstream inputFile("workers.bin", std::ios::binary);
    Worker worker;
    while (inputFile.read((char*)&worker, sizeof(worker))) {
        if (worker.gender == "женский" && worker.education != "высшее" && worker.age >= 60) {
            std::cout << "Фамилия: " << worker.surname << '\n';
            std::cout << "Возраст: " << worker.age << '\n';
            std::cout << "Образование: " << worker.education << '\n';
            std::cout << "Должность: " << worker.position << '\n';
            std::cout << "Пол: " << worker.gender << '\n';
            std::cout << "-----------------\n";
        }
    }

    return 0;
}
