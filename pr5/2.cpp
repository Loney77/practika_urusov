#include <iostream>
#include <string>

template<typename T>
class Complex {
public:
    Complex(T real, T imag) : real_(real), imag_(imag) {}

    T getReal() const {
        return real_;
    }

    T getImag() const {
        return imag_;
    }

    void setReal(T real) {
        real_ = real;
    }

    void setImag(T imag) {
        imag_ = imag;
    }

    Complex<T> operator+(const Complex<T>& other) const {
        return Complex<T>(real_ + other.real_, imag_ + other.imag_);
    }

    Complex<T> operator-(const Complex<T>& other) const {
        return Complex<T>(real_ - other.real_, imag_ - other.imag_);
    }

    Complex<T> operator*(const Complex<T>& other) const {
        T real = real_ * other.real_ - imag_ * other.imag_;
        T imag = real_ * other.imag_ + imag_ * other.real_;
        return Complex<T>(real, imag);
    }

    Complex<T> operator/(const Complex<T>& other) const {
        T denominator = other.real_ * other.real_ + other.imag_ * other.imag_;
        T real = (real_ * other.real_ + imag_ * other.imag_) / denominator;
        T imag = (imag_ * other.real_ - real_ * other.imag_) / denominator;
        return Complex<T>(real, imag);
    }

private:
    T real_;
    T imag_;
};

int main() {
    setlocale(LC_ALL, "RUS");
    try {
        // Вещественные части и мнимые части как числа типа double
        Complex<double> complexDouble1(1.5, 2.7);
        Complex<double> complexDouble2(3.9, 4.1);

        std::cout << "Сложение комплексных чисел с вещественными частями и мнимыми частями типа double:" << std::endl;
        Complex<double> sumDouble = complexDouble1 + complexDouble2;
        std::cout << "Результат: " << sumDouble.getReal() << " + " << sumDouble.getImag() << "i" << std::endl;

        std::cout << "Вычитание комплексных чисел с вещественными частями и мнимыми частями типа double:" << std::endl;
        Complex<double> diffDouble = complexDouble1 - complexDouble2;
        std::cout << "Результат: " << diffDouble.getReal() << " + " << diffDouble.getImag() << "i" << std::endl;

        std::cout << "Умножение комплексных чисел с вещественными частями и мнимыми частями типа double:" << std::endl;
        Complex<double> mulDouble = complexDouble1 * complexDouble2;
        std::cout << "Результат: " << mulDouble.getReal() << " + " << mulDouble.getImag() << "i" << std::endl;

        std::cout << "Деление комплексных чисел с вещественными частями и мнимыми частями типа double:" << std::endl;
        Complex<double> divDouble = complexDouble1 / complexDouble2;
        std::cout << "Результат: " << divDouble.getReal() << " + " << divDouble.getImag() << "i" << std::endl;

        // Вещественные части и мнимые части как числа типа int
        Complex<int> complexInt1(1, 2);
        Complex<int> complexInt2(3, 4);

        std::cout << "\nСложение комплексных чисел с вещественными частями и мнимыми частями типа int:" << std::endl;
        Complex<int> sumInt = complexInt1 + complexInt2;
        std::cout << "Результат: " << sumInt.getReal() << " + " << sumInt.getImag() << "i" << std::endl;

        std::cout << "Вычитание комплексных чисел с вещественными частями и мнимыми частями типа int:" << std::endl;
        Complex<int> diffInt = complexInt1 - complexInt2;
        std::cout << "Результат: " << diffInt.getReal() << " + " << diffInt.getImag() << "i" << std::endl;

        std::cout << "Умножение комплексных чисел с вещественными частями и мнимыми частями типа int:" << std::endl;
        Complex<int> mulInt = complexInt1 * complexInt2;
        std::cout << "Результат: " << mulInt.getReal() << " + " << mulInt.getImag() << "i" << std::endl;

        std::cout << "Деление комплексных чисел с вещественными частями и мнимыми частями типа int:" << std::endl;
        Complex<int> divInt = complexInt1 / complexInt2;
        std::cout << "Результат: " << divInt.getReal() << " + " << divInt.getImag() << "i" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
