# Homework: Реалізація зберігання товарів з використанням інтерфейсів
`main.cpp` містить просту програму для управління товарами.
Ваше завдання — покращити цю програму, додавши клас для зберігання товарів та інтерфейси для доступу до них.

Вимоги:
- всі класи повинні бути реалізовані в окремих файлах з відповідними заголовочними файлами. 

## Step-1. Додати класс ProductStore. який реалізує зберігання товарів. 
```cpp
class ProductStore {
private:
    std::vector<Product> products;
public:
    void addProduct(const Product& product);
    Product getProductByIndex(int index) const;
    std::vector<Product> getAllProducts() const;
    int Size() const;
};
```

`методи класу ProductStore потрібно реалізувати самостійно!`


## Step-2. Додати Інтерфейси 

додайте інтерфейс IProductStore — інтерфейс для доступу до товарів:
його ціль — приховати реалізацію зберігання товарів від клієнтського коду.

```cpp
class IProductStore {
public:
    virtual void addProduct(const Product& product) = 0;
    virtual Product getProductByIndex(int index) const = 0;
    virtual std::vector<Product> getAllProducts() const = 0;
    virtual int Size() const = 0;
    virtual ~IProductStore() = default;
};
```

### Реалізуйте клас InMemoryProductStore, який реалізує інтерфейс IProductStore, використовуючи std::vector для зберігання товарів в пам'яті.
```cpp
class InMemoryProductStore : public IProductStore {
private:
    std::vector<Product> products;
public:
    void addProduct(const Product& product) override;
    Product getProductByIndex(int index) const override;
    std::vector<Product> getAllProducts() const override;
    int Size() const override;
    ~InMemoryProductStore() override = default;
};
```

`методи класу InMemoryProductStore потрібно реалізувати самостійно!`

## Step-3. Додати Реалізацію класу FileProductStore, який реалізує інтерфейс IProductStore, використовуючи файл для зберігання товарів на диску.
```cpp
class FileProductStore : public IProductStore {
private:
    std::string filename;
public:
    FileProductStore(const std::string& file);
    void addProduct(const Product& product) override;
    Product getProductByIndex(int index) const override;
    std::vector<Product> getAllProducts() const override;
    int Size() const override;
    ~FileProductStore() override = default;
};
```  

`методи класу FileProductStore потрібно реалізувати самостійно!`