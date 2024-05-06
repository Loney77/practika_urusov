#include <iostream>
#include <list>

int main() {
    std::list<double> numbers = { 1.2, -2, 3.4, -5.6, 7.8, 9.0 }; // Ваш список чисел
    auto it = numbers.begin();
    while (it != numbers.end()) {
        if (*it < 0) {
            it = numbers.insert(++it, 1.5);
        }
        else if (*it >= 2 && *it <= 5) {
            it = numbers.erase(it);
        }
        else {
            ++it;
        }
    }

    // Выводим список
    for (const auto& num : numbers) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}
