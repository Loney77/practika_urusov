#include <iostream>
#include <list>
#include <string>

template<typename T>
class Queue {
public:
    Queue() {}

    void push(const T& value) {
        try {
            server.push_back(value);
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка при добавлении элемента в очередь: " << e.what() << std::endl;
        }
    }

    T pop() {
        try {
            if (server.empty()) {
                throw std::runtime_error("Очередь пуста.");
            }
            T value = server.front();
            server.pop_front();
            return value;
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка при извлечении элемента из очереди: " << e.what() << std::endl;
            return T();
        }
    }

    bool isEmpty() const {
        return server.empty();
    }

private:
    std::list<T> server;
};

int main() {
    try {
        Queue<int> intQueue;
        intQueue.push(1);
        intQueue.push(2);
        intQueue.push(3);

        while (!intQueue.isEmpty()) {
            std::cout << intQueue.pop() << " ";
        }
        std::cout << std::endl;

        Queue<double> doubleQueue;
        doubleQueue.push(1.5);
        doubleQueue.push(2.7);
        doubleQueue.push(3.9);

        while (!doubleQueue.isEmpty()) {
            std::cout << doubleQueue.pop() << " ";
        }
        std::cout << std::endl;

        Queue<std::string> stringQueue;
        stringQueue.push("Hello");
        stringQueue.push("World");
        stringQueue.push("!");

        while (!stringQueue.isEmpty()) {
            std::cout << stringQueue.pop() << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
