#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    Product(string name, double price)
        : name_(std::move(name)), price_(price) {}

    void Print(size_t index) const {
        cout << index + 1 << ". " << name_ << " - $" << price_ << "\n";
    }

    string GetName() const { return name_; }
    double GetPrice() const { return price_; }

private:
    string name_;
    double price_;
};

enum class MenuAction {
    AddProduct = 1,
    ListProducts,
    Exit
};

// Прототипи
void showMainMenu();
Product addProduct();
void showListProducts(const vector<Product>& products);

int main() {
    vector<Product> products;
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
                products.push_back(newProduct);
            }
                break;
            case MenuAction::ListProducts:
                showListProducts(products);
                break;
            case MenuAction::Exit:
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (static_cast<MenuAction>(choice) != MenuAction::Exit);

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
