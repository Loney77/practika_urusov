#include <iostream>
#include <list>

class Stack {
    std::list<int> data;

public:
    void push(int value) {
        data.push_front(value);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_front();
        }
    }

    void print() {
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    int sumPositive() {
        int sum = 0;
        for (int value : data) {
            if (value > 0) {
                sum += value;
            }
        }
        return sum;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Stack stack;
    stack.push(-5);
    stack.push(3);
    stack.push(-4);
    stack.push(5);
    stack.print();  // Распечатать содержимое стека

    stack.pop();  // Удалить один элемент из стека
    stack.push(10);  // Добавить число 10 в стек
    stack.print();  // Распечатать содержимое стека еще раз

    std::cout << "Сумма всех положительных элементов: " << stack.sumPositive() << std::endl;

    return 0;
}

