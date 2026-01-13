#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Product {
public:
    Product(string name, int price)
        : name_(std::move(name)), price_(price) {}

    void Print(size_t index) const {
        cout << index + 1 << ". " << name_ << " - $" << price_ << "\n";
    }

    string GetName() const { return name_; }
    int GetPrice() const { return price_; }

private:
    string name_;
    int price_;
};

enum class MenuAction {
    AddProduct = 1,
    ListProducts,
    Exit
};

//-------------------
class IProductStore {
public:
    virtual int AddProduct(const Product& product) = 0;
    virtual const std::vector<Product> GetProducts() const = 0;
    virtual ~IProductStore() = default; // {};
};

class ProductStoreList : public IProductStore {
    std::list<Product> products;

public:
    ProductStoreList(){
        std::cout << "Using List as storage type.\n";
    };
    int AddProduct(const Product& product) override {
        products.insert(products.end(), product);
        return products.size(); // Assuming 0 indicates success
    }
    const std::vector<Product> GetProducts() const override {
        return std::vector<Product>(products.begin(), products.end());
    }
};

class ProductStoreVector : public IProductStore {
    std::vector<Product> products;

public:
    ProductStoreVector(){
        std::cout << "Using Vector as storage type.\n";
    };
    int AddProduct(const Product& product) override{
        products.push_back(product);
        return products.size(); // Assuming 0 indicates success
    }
    const std::vector<Product> GetProducts() const override {
        return std::vector<Product>(products.begin(), products.end());
    }
};


class ProductStoreVector2 : public IProductStore {
    std::vector<Product> products;

public:
    ProductStoreVector2(){
        std::cout << "Using Vector as storage type.\n";
    };
    int AddProduct(const Product& product) override{
        products.emplace_back(product);
        return products.size(); // Assuming 0 indicates success

    }
    const std::vector<Product> GetProducts() const {
        return std::vector<Product>(products.begin(), products.end());
    }
};


// Прототипи
void showMainMenu();
Product addProduct();
void showListProducts(const std::vector<Product>& products);

int main() {
    IProductStore* store = nullptr;

    std::cout << "Select storage type:\n1. List\n2. Vector(Default)\nChoose an option: ";
    int storageChoice;
    std::cin >> storageChoice;

    if (storageChoice == 1) {
        store = new ProductStoreList();
    } else {
        store = new ProductStoreVector2();
    }

    int choice;

    do {
        showMainMenu();
        cout << "Choose an option: ";
        cin >> choice;

        MenuAction action = static_cast<MenuAction>(choice);

        switch (action) {
            case MenuAction::AddProduct:
            {
                const Product newProduct = addProduct();
                const int result = store->AddProduct(newProduct);
                if (result > 0) {
                    cout << "Product added successfully.\n";
                } else {
                    cout << "Failed to add product.\n";
                }
                break;
            }
            case MenuAction::ListProducts:
                showListProducts(store->GetProducts());
                break;
            case MenuAction::Exit:
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (static_cast<MenuAction>(choice) != MenuAction::Exit);

    delete store;

    return 0;
}

void showMainMenu() {
    cout << "----- Main Menu ----- \n"
         "1. Add product\n"
         "2. List products\n"
         "3. Exit\n\n";
}

void showListProducts(const vector<Product>& products) {
    cout << "----- List Products ----- \n";
    if (products.empty()) {
        cout << "No products available.\n";
        return;
    }

    cout << "Products:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        products[i].Print(i);
    }

    cout << "\n";
}

Product addProduct() {
    string name;
    double price;

    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product price: ";
    cin >> price;
    
    cout << "\n";
    
    return Product(name, price);
}
