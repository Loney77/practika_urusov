#include <iostream>
#include <list>

int main() {
    setlocale(LC_ALL, "RUS");
    std::list<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double sum = 0.0;
    int count = 0;

    auto it = numbers.begin();
    std::advance(it, 4);

    for (; it != numbers.end(); ++it) {
        sum += *it;
        ++count;
    }

    double average = (count > 0) ? sum / count : 0;

    std::cout << "Среднее арифметическое: " << average << std::endl;

    return 0;
}

