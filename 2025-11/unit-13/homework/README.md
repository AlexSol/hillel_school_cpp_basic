### Задача 1: Лічильник об'єктів

Створи клас MyClass, який має:

статичне поле objectCount, що підраховує кількість створених об'єктів
конструктор, який збільшує objectCount
статичний метод PrintObjectCount()

Очікувана поведінка:
```cpp
MyClass a, b, c;
MyClass::PrintObjectCount(); // Виведе: 3
```

### Задача 2: Статистика студентів

Клас Student:

- поля: name, grade
- статичне поле count
- статичне поле averageGrade (сума оцінок / кількість студентів)
- оновлення count та averageGrade відбувається в конструкторі

Очікувана поведінка:
```cpp
Student s1("Alice", 90);
Student s2("Bob", 80);
std::cout << "Кількість студентів: " << Student::count << std::endl; // Виведе: 2
std::cout << "Середній бал: " << Student::averageGrade << std::endl; // Виведе: 85
```