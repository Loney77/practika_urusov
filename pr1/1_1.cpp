#include <iostream>
#include <queue>

int main() {
    setlocale(LC_ALL, "RUS");
    std::queue<int> q;
    int n;
    std::cout << "Введите количество элементов в очереди: ";
    std::cin >> n;

    std::cout << "Введите элементы очереди:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        q.push(x);
    }

    int even_count = 0;
    std::cout << "Элементы очереди:\n";
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        std::cout << x << ' ';
        if (x % 2 == 0) {
            ++even_count;
        }
    }
    std::cout << "\nКоличество четных элементов: " << even_count << '\n';

    return 0;
}
