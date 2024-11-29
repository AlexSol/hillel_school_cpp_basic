#include <iostream>
#include <string>

// Базовий клас
class Car {
public:
    virtual void start() const { // Віртуальний метод
        std::cout << "Starting a generic car..." << std::endl;
    }

    virtual ~Car() = default; // Віртуальний деструктор
};

// Похідний клас: ElectricCar
class ElectricCar : public Car {
public:
    void start() const override { // Перевизначення методу
        std::cout << "Starting an electric car silently..." << std::endl;
    }
};

// Похідний клас: GasolineCar
class GasolineCar : public Car {
public:
    void start() const override { // Перевизначення методу
        std::cout << "Starting a gasoline car with a roar..." << std::endl;
    }
};

int main() {
    Car* car1 = new Car();           // Базовий об'єкт
    Car* car2 = new ElectricCar();  // Об'єкт похідного класу
    Car* car3 = new GasolineCar();  // Інший об'єкт похідного класу

    // Поліморфний виклик
    car1->start(); // Виведе: Starting a generic car...
    car2->start(); // Виведе: Starting an electric car silently...
    car3->start(); // Виведе: Starting a gasoline car with a roar...

    // Звільнення пам'яті
    delete car1;
    delete car2;
    delete car3;

    return 0;
}
