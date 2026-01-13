#include <iostream>
using namespace std;

class Box {
private:
    double width; // Приватна змінна
public:
    // Конструктор
    Box(double w) : width(w) {}

};

// Реалізація функції-друга
void printWidth(const Box& b) {
    cout << "Ширина коробки: " << b.width << endl;
}


int main() {
    Box box1(5.5);

    box1.width = 10.0; // Помилка: width є приватним членом класу Box

    printWidth(box1); // Виклик функції-друга

    std::clog<< "мій куб:" << box1 << "\n";


    return 0;
}
