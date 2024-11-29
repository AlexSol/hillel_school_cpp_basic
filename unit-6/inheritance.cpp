#include <iostream>
#include <string>

// Базовий клас
class Animal {
protected:
    std::string name;

public:
    Animal(std::string aName) : name(aName) {}

    void eat() {
        std::cout << name << " is eating." << std::endl;
    }
};

// Похідний клас
class Dog : public Animal {
public:
    Dog(std::string aName) : Animal(aName) {}

    void bark() {
        std::cout << name << " is barking." << std::endl;
    }
};

int main() {
    Dog dog("Buddy");
    dog.eat();   // Використання методу базового класу
    dog.bark();  // Використання методу похідного класу

    return 0;
}
