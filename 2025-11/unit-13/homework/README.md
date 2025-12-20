### Лічильник об'єктів

Створи клас MyClass, який має:

статичне поле objectCount, що підраховує кількість створених об'єктів
конструктор, який збільшує objectCount
статичний метод PrintObjectCount()

Очікувана поведінка:
```cpp
MyClass a, b, c;
MyClass::PrintObjectCount(); // Виведе: 3
```