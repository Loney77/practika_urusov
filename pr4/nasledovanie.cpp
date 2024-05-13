#include <iostream>
#include <vector>
#include <memory>
#include <string>

class CVehicle {
public:
    virtual ~CVehicle() {}

    virtual void setCoordinates(double x, double y) = 0;
    virtual std::string getCoordinates() const = 0;

    virtual void setPrice(double price) = 0;
    virtual double getPrice() const = 0;

    virtual void setSpeed(double speed) = 0;
    virtual double getSpeed() const = 0;

    virtual void setYear(int year) = 0;
    virtual int getYear() const = 0;

    virtual void setPassengers(int passengers) = 0;
    virtual int getPassengers() const = 0;

    virtual void setPort(const std::string& port) = 0;
    virtual std::string getPort() const = 0;

    virtual void setHeight(double height) = 0;
    virtual double getHeight() const = 0;
};

class CPlane : public CVehicle {
public:
    void setCoordinates(double x, double y) override {
        coordinatesX = x;
        coordinatesY = y;
    }

    std::string getCoordinates() const override {
        return "Координаты: (" + std::to_string(coordinatesX) + ", " + std::to_string(coordinatesY) + ")";
    }

    void setPrice(double price) override {
        price_ = price;
    }

    double getPrice() const override {
        return price_;
    }

    void setSpeed(double speed) override {
        speed_ = speed;
    }

    double getSpeed() const override {
        return speed_;
    }

    void setYear(int year) override {
        year_ = year;
    }

    int getYear() const override {
        return year_;
    }

    void setPassengers(int passengers) override {
        passengers_ = passengers;
    }

    int getPassengers() const override {
        return passengers_;
    }

    void setPort(const std::string& port) override {}

    std::string getPort() const override {
        return "";
    }

    void setHeight(double height) override {
        height_ = height;
    }

    double getHeight() const override {
        return height_;
    }

private:
    double coordinatesX = 0;
    double coordinatesY = 0;
    double price_ = 0;
    double speed_ = 0;
    int year_ = 0;
    int passengers_ = 0;
    double height_ = 0;
};

class CCar : public CVehicle {
public:
    void setCoordinates(double x, double y) override {
        coordinatesX = x;
        coordinatesY = y;
    }

    std::string getCoordinates() const override {
        return "Координаты: (" + std::to_string(coordinatesX) + ", " + std::to_string(coordinatesY) + ")";
    }

    void setPrice(double price) override {
        price_ = price;
    }

    double getPrice() const override {
        return price_;
    }

    void setSpeed(double speed) override {
        speed_ = speed;
    }

    double getSpeed() const override {
        return speed_;
    }

    void setYear(int year) override {
        year_ = year;
    }

    int getYear() const override {
        return year_;
    }

    void setPassengers(int passengers) override {
        passengers_ = passengers;
    }

    int getPassengers() const override {
        return passengers_;
    }

    void setPort(const std::string& port) override {}

    std::string getPort() const override {
        return "";
    }

    void setHeight(double height) override {}

    double getHeight() const override {
        return 0;
    }

private:
    double coordinatesX = 0;
    double coordinatesY = 0;
    double price_ = 0;
    double speed_ = 0;
    int year_ = 0;
    int passengers_ = 0;
};

class CShip : public CVehicle {
public:
    void setCoordinates(double x, double y) override {
        coordinatesX = x;
        coordinatesY = y;
    }

    std::string getCoordinates() const override {
        return "Координаты: (" + std::to_string(coordinatesX) + ", " + std::to_string(coordinatesY) + ")";
    }

    void setPrice(double price) override {
        price_ = price;
    }

    double getPrice() const override {
        return price_;
    }

    void setSpeed(double speed) override {
        speed_ = speed;
    }

    double getSpeed() const override {
        return speed_;
    }

    void setYear(int year) override {
        year_ = year;
    }

    int getYear() const override {
        return year_;
    }

    void setPassengers(int passengers) override {
        passengers_ = passengers;
    }

    int getPassengers() const override {
        return passengers_;
    }

    void setPort(const std::string& port) override {
        port_ = port;
    }

    std::string getPort() const override {
        return port_;
    }

    void setHeight(double height) override {}

    double getHeight() const override {
        return 0;
    }

private:
    double coordinatesX = 0;
    double coordinatesY = 0;
    double price_ = 0;
    double speed_ = 0;
    int year_ = 0;
    int passengers_ = 0;
    std::string port_ = "";
};

int main() {
    setlocale(LC_ALL, "RUS");
    // Создаем список объектов в динамической памяти
    std::vector<std::unique_ptr<CVehicle>> vehicles;
    vehicles.push_back(std::make_unique<CPlane>());
    vehicles.push_back(std::make_unique<CCar>());
    vehicles.push_back(std::make_unique<CShip>());

    // Меню для проверки методов классов
    int choice = 0;
    while (choice != 5) {
        std::cout << "1. Установить координаты" << std::endl;
        std::cout << "2. Установить параметры средств передвижения" << std::endl;
        std::cout << "3. Установить параметры для самолета и корабля" << std::endl;
        std::cout << "4. Получить информацию об объектах" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double x, y;
            std::cout << "Введите координаты X и Y: ";
            std::cin >> x >> y;
            for (auto& vehicle : vehicles) {
                vehicle->setCoordinates(x, y);
            }
            break;
        }
        case 2: {
            double price, speed;
            int year;
            std::cout << "Введите цену, скорость и год выпуска: ";
            std::cin >> price >> speed >> year;
            for (auto& vehicle : vehicles) {
                vehicle->setPrice(price);
                vehicle->setSpeed(speed);
                vehicle->setYear(year);
            }
            break;
        }
        case 3: {
            int passengers;
            std::string port;
            double height;
            std::cout << "Введите количество пассажиров и высоту для самолета, порт приписки для корабля: ";
            std::cin >> passengers >> height;
            std::cin.ignore();
            std::getline(std::cin, port);
            for (auto& vehicle : vehicles) {
                if (auto* plane = dynamic_cast<CPlane*>(vehicle.get())) {
                    plane->setPassengers(passengers);
                    plane->setHeight(height);
                }
                else if (auto* ship = dynamic_cast<CShip*>(vehicle.get())) {
                    ship->setPassengers(passengers);
                    ship->setPort(port);
                }
            }
            break;
        }
        case 4: {
            for (const auto& vehicle : vehicles) {
                std::cout << vehicle->getCoordinates() << std::endl;
            }
            break;
        }
        case 5:
            break;
        default:
            std::cout << "Неправильный выбор" << std::endl;
        }
    }

    return 0;
}