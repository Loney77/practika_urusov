#include <iostream>
#include <list>

int main() {
    std::list<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    if (numbers.size() > 1) {
        numbers.pop_back();
        numbers.pop_back();
    }
    else {
        numbers.clear();
    }

    for (auto& num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
