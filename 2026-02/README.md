# Modern C++: C++11 → C++23 + std::filesystem

## 1. Еволюція стандартів
- C++11 (2011): Введення лямбда-функцій, авто-типів, розширених можливостей шаблонів, нових бібліотек (наприклад, `<thread>`, `<chrono>`, `<regex>`).
- C++14 (2014): Покращення лямбда-функцій, розширення можливостей шаблонів, введення `std::make_unique`.
- C++17 (2017): Введення `std::optional`, `std::variant`, `std::any`, структурні зв'язування, нові алгоритми.
- C++20 (2020): Введення `concepts`, корутин, модулів, нових бібліотек (наприклад, `<format>`, `<span>`).
- C++23 (2023): Подальші покращення, нові можливості та оптимізації.(`expected`)

Modern C++ = безпечність + читабельність + контроль ресурсів

## C++ nullptr
До C++11 для представлення відсутності вказівника використовувалися макроси `NULL` або `0`, що могло призводити до неоднозначностей та помилок. З C++11 з'явився `nullptr`, який є спеціальним літералом для представлення відсутності вказівника, що забезпечує більш безпечне та однозначне представлення відсутності вказівника.

```cppvoid func(int* ptr) {
    if (ptr == nullptr) {
        std::cout << "ptr is null" << std::endl;
    } else {
        std::cout << "ptr is not null" << std::endl;
    }
}
```

## 1. C++11: Uniform Initialization
До C++11 для ініціалізації змінних використовувалися різні синтаксиси, що могло призводити до плутанини та помилок. З C++11 з'явився уніфікований синтаксис ініцілізації, який дозволяє використовувати однаковий синтаксис для ініціалізації змінних, масивів, структур та класів. 
```cpp
int x = 5; // До C++11
std::vector<int> v = {1, 2, 3}; // До C++11
``` 

### C++ enuma class
До C++11 для оголошення перерахувань використовувалися звичайні `enum`, які могли призводити до проблем з типами та іменами. З C++11 з'явився `enum class`, який дозволяє створювати типобезпечні перерахування з власною областю видимості.
```cpp
enum Color { Red, Green, Blue }; // До C++11
enum class Color { Red, Green, Blue }; // C++11
``` 

преваги `enum class`:
- Типобезпечність: `enum class` не дозволяє неявне перетворення до інших типів, що запобігає помилкам типів.
- Власна область видимості: Члени `enum class` не потрапляють у глобальну область видимості, що запобігає конфліктам іменами.
- Можливість вказувати тип зберігання: `enum class` дозволяє вказувати тип зберігання (наприклад, `enum class Color : uint8_t { Red, Green, Blue };`), що може бути корисним для оптимізації пам'яті.   


## 2. C++11: auto
До C++11 для оголошення змінної потрібно було явно вказувати її тип, що могло бути громіздким, особливо при роботі з ітераторами або складними типами. З C++11 з'явився ключове слово `auto`, яке дозволяє компілятору виводити тип змінної на основі її ініціалізації.

```cpp
std::vector<int>::iterator it = v.begin();
```

```cpp
auto it = v.begin(); // Компилятор виводить тип std::vector<int>::iterator
```

# 3. Range-based for
До C++11 для ітерування по контейнерах потрібно було використовувати ітератори або індекси, що могло бути не дуже зручно. З C++11 з'явився range-based for loop, який дозволяє легко ітерувати по елементам контейнера.

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
}
```

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
for (const auto& element : v) {
    std::cout << element << std::endl;
}
```

Переваги:
- Без індексів
- Менше помилок


## 4. Лямбда-функції
До C++11 для створення анонімних функцій потрібно було використовувати функціональні об'єкти або вказівники на функції, що могло бути громіздким. З C++11 з'явилися лямбда-функції, які дозволяють створювати анонімні функції безпосередньо в місці їх використання.

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::vector<int> v = {1, 2, 3, 4, 5};
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a > b; // Сортування у зворотному порядку
});
```

Capture:
- `[&]` - захоплення всіх змінних за посиланням
- `[=]` - захоплення всіх змінних за значенням
- `[this]` - захоплення вказівника на поточний об'єкт
- `[x, &y]` - захоплення змінної `x` за значенням та `y` за посиланням  

## 5. Smart Pointers
До C++11 для управління динамічною пам'яттю використовувалися сирі вказівники, що могло призводити до витоків пам'яті та інших проблем. З C++11 з'явилися розумні вказівники (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`), які автоматично керують життєвим циклом об'єктів.

```cpp
std::unique_ptr<int> ptr(new int(5)); // Унікальний вказівник
std::shared_ptr<int> sharedPtr1(new int(10)); // Спільний вказівник
std::shared_ptr<int> sharedPtr2 = sharedPtr1; // Копіювання спільного вказівника
std::weak_ptr<int> weakPtr = sharedPtr1; // Слабкий вказівник
```

ми можемо використовувати `std::make_unique` та `std::make_shared` для створення розумних вказівників, що є більш безпечним та ефективним способом:

```cpp
auto ptr = std::make_unique<int>(5); // Унікальний вказівник
auto sharedPtr1 = std::make_shared<int>(10); // Спільний вказівник
auto sharedPtr2 = sharedPtr1; // Копіювання спільного вказівника
auto weakPtr = std::weak_ptr<int>(sharedPtr1); // Слабкий вказівник
```

старинян розумних вказівників для управління ресурсами, такими як файли або мережеві з'єднання, що забезпечує автоматичне закриття ресурсів при виході з області видимості. Наприклад:

```cpp
void processFile(const std::string& filename) {
    std::unique_ptr<std::ifstream> file(new std::ifstream(filename));
    if (!file->is_open()) {
        throw std::runtime_error("Could not open file");
    }
    // Обробка файлу
} // Файл буде автоматично закритий при виході з області видимості
```

старинян розумних вказівників для управління масивами або іншими ресурсами, що забезпечує автоматичне звільнення пам'яті при виході з області видимості. Наприклад:

```cpp
void processArray(size_t size) {
    std::unique_ptr<int[]> arr(new int[size]);
    // Ініціалізація та обробка масиву
} // Пам'ять буде автоматично звільнена при виході з області видимості
```

і приклад масивів із shared_ptr:
// C++11 не підтримує `std::make_shared` для масивів, тому потрібно    
// використовувати конструктор `std::shared_ptr` з власним делітером
    

```cpp
void processSharedArray(size_t size) {
    std::shared_ptr<int[]> arr(new int[size], std::default_delete<int[]>()); 
    
    // Ініціалізація та обробка масиву
} // Пам'ять буде автоматично звільнена при виході з області видимості
``` 

C++17 додав підтримку `std::make_shared` для масивів, що робить код більш чистим та безпечним:

```cpp
#include <cstddef>
#include <iostream>
#include <memory>
 
int main()
{
    const std::size_t arr_size = 10;
    std::shared_ptr<int[]> pis(new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    for (std::size_t i = 0; i < arr_size; ++i)
        std::cout << pis[i] << ' ';
    std::cout << '\n';
}
```


Переваги:
- Автоматичне звільнення пам'яті
- Запобігання витоків пам'яті
- Безпечне спільне використання ресурсів
- Уникнення циклічних посилань (з `std::weak_ptr`)
- Покращення читабельності та підтримки коду    
- Підвищення безпеки та надійності програмного забезпечення
- Зменшення кількості помилок, пов'язаних з управлінням пам'яттю

## 6. Move Semantics
До C++11 для копіювання об'єктів використовувалися конструктори копіювання та оператори присвоєння, що могло бути неефективним для великих об'єктів. З C++11 з'явилися семантики переміщення, які дозволяють ефективно передавати ресурси без необхідності копіювання.

```cpp
std::string s1 = "Hello";
std::string s2 = std::move(s1);
```

Що відбувається?
- Дані НЕ копіюються
- Передається ownership


```cpp
class MyClass {
public:
    MyClass(size_t size) : data(new int[size]), size(size) {}
    ~MyClass() { delete[] data; }
    // Конструктор копіювання
    MyClass(const MyClass& other) : data(new int[other.size]), size(other.size) {
        std::copy(other.data, other.data + size, data);
    }
    // Оператор присвоєння копіювання
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
    // Конструктор переміщення
    MyClass(MyClass&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    // Оператор присвоєння переміщення
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
private:
    int* data;
    size_t size;
};
```
Переваги:
- Ефективне переміщення ресурсів без копіювання
- Покращення продуктивності при роботі з великими об'єктами
- Зменшення навантаження на систему при передачі об'єктів
- Підвищення ефективності при використанні контейнерів та алгоритмів
- Зменшення кількості помилок, пов'язаних з управлінням ресурсами
- Покращення читабельності та підтримки коду    

## 7. Правило п'яти(Rule of 5):
Якщо є:
- destructor
- copy constructor
- copy assignment
То треба подумати про:
- move constructor
- move assignment

Якщо клас визначає будь-який з наступних: конструктор копіювання, оператор присвоєння копіювання, конструктор переміщення, оператор присвоєння переміщення, або деструктор, то він повинен визначати всі ці п'ять функцій для правильного управління ресурсами та запобігання витоків пам'яті або інших проблем з ресурсами. Це правило допомагає забезпечити безпечне та ефективне управління ресурсами в класах, які використовують динамічну пам'ять або інші ресурси, що потребують спеціального управління.  

## 8. C++14 - Покращення лямбда-функцій (можливість використовувати auto в параметрах)
- Generic lambda
- auto return type

До C++14 лямбда-функції не підтримували використання `auto` в параметрах, що обмежувало їх гнучкість. З C++14 з'явилася можливість використовувати `auto` в параметрах лямбда-функцій, що дозволяє створювати більш універсальні та гнучкі лямбда-функції.

```cpp
auto add(auto a, auto b) {
    return a + b;
}
```

## 9. C++17 
- std::optional
- structured bindings
- std::string_view
- std::variant
- std::filesystem

### std::optional
До C++17 для представлення відсутності значення використовувалися вказівники або спеціальні значення (наприклад, `-1` для чисел), що могло призводити до помилок. З C++17 з'явився `std::optional`, який дозволяє безпечно представляти відсутність значення.

```cpp
std::optional<int> divide(int a, int b) {
    if (b == 0)
        return std::nullopt;
    return a / b;
}
```
### structured bindings
До C++17 для розпакування структур або пар потрібно було використовувати окремі змінні або функції. З C++17 з'явилися структурні зв'язування, які дозволяють легко розпаковувати структури або пари в окремі змінні.

```cpp
std::pair<int, int> p{1,2};
auto [x, y] = p;
```

```cpp
std::tuple<int, std::string, double> t{1, "Hello", 3.14};
auto [i, s, d] = t;
``` 

### std::string_view
До C++17 для роботи з рядками використовувалися `std::string`, що могло бути неефективним при передачі великих рядків або при роботі з літералами. З C++17 з'явився `std::string_view`, який дозволяє ефективно працювати з рядками без необхідності копіювання.

```cpp
void printString(std::string_view str) {
    std::cout << str << std::endl;
}
printString("Hello, World!"); // Можна передавати літерали без копіювання
```

### std::variant
До C++17 для представлення значень, які можуть бути одного з кількох типів, використовувалися об'єкти базового класу або інші складні конструкції. З C++17 з'явився `std::variant`, який дозволяє безпечно представляти значення, які можуть бути одного з кількох типів.

```cpp
std::variant<int, std::string> v;
v = 42; // v містить int
v = "Hello"; // v містить std::string
```

### std::filesystem
До C++17 для роботи з файловою системою використовувалися сторонні бібліотеки або системні виклики, що могло бути неефективним та складним. З C++17 з'явився `std::filesystem`, який дозволяє ефективно працювати з файловою системою, надаючи зручний інтерфейс для роботи з файлами та директоріями.

Кросплатформена робота з файлами:
- path
- exists
- create_directory
- directory_iterator

```cpp
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path path = "example.txt";
    if (fs::exists(path)) {
        std::cout << path << " exists." << std::endl;
    } else {
        std::cout << path << " does not exist." << std::endl;
    }
}
```

### Робота з path
```cpp
#include <filesystem>
namespace fs = std::filesystem;

fs::path p = "example.txt";

std::cout << p.filename() << "\n";
std::cout << p.extension() << "\n";
std::cout << p.parent_path() << "\n";
```

### Перевірка існування
```cpp
#include <filesystem>
namespace fs = std::filesystem;

fs::path p = "example.txt";
if (fs::exists(p)) {
    std::cout << p << " exists." << std::endl;
} else {
    std::cout << p << " does not exist." << std::endl;
}
```

### Обхід директорії
```cpp
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
fs::path dir = "my_directory";
for (const auto& entry : fs::directory_iterator(dir)) {
    std::cout << entry.path() << std::endl;
}
```

### Рекурсивний обхід
```cpp
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
fs::path dir = "my_directory";
for (const auto& entry : fs::recursive_directory_iterator(dir)) {
    std::cout << entry.path() << std::endl;
}
```

### Приклад: знайти всі .cpp файли в директорії
```cpp
for (const auto& entry :
     fs::recursive_directory_iterator(".")) {

    if (entry.path().extension() == ".cpp") {
        std::cout << entry.path() << "\n";
    }
}
```