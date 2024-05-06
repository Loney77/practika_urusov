#include <iostream>
#include <list>
#include <cmath>

int main() {
    std::list<double> numbers = { 1.6, 2.4, 3.7, 4.2, 5.1 };

    for (auto it = numbers.begin(); it != numbers.end(); ) {
        if (std::fmod(*it, 1.0) > 0.5) {
            it = numbers.erase(it);
        }
        else {
            ++it;
        }
    }

    for (const auto& num : numbers) {
        std::cout << num << ' ';
    }

    return 0;
}

