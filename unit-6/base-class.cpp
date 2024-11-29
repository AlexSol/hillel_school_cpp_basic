#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    // Метод класу
    void introduce() {
        std::cout << "Hi, my name is " << name << " and I am " << age << " years old." << std::endl;
    }
};

struct Point {
    int x, y;

    void display() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

class Circle {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    void displayArea() {
        std::cout << "Area: " << 3.14 * radius * radius << std::endl;
    }
};

// Ключові моменти роботи з класами
class Car {
public:
    std::string brand;

    Car(std::string b) : brand(b) { // Конструктор
        std::cout << "Car " << brand << " created." << std::endl;
    }

    ~Car() { // Деструктор
        std::cout << "Car " << brand << " destroyed." << std::endl;
    }
};

int main() {
    Person person;         // Створення об'єкта класу Person
    person.name = "Alice"; // Ініціалізація полів об'єкта
    person.age = 25;

    person.introduce();    // Виклик методу об'єкта


    Point p = {2, 3};
    p.display(); // Вивід: Point(2, 3)

    Circle c(5.0);
    c.displayArea(); // Вивід: Area: 78.5


    Car car("Tesla"); // Створення об'єкта класу Car


    return 0;
}
