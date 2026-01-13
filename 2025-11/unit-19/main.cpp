#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <fstream>

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
    int typeStorage; // 1 - List, 2 - Vector, 3 - FileCSV
public:
    IProductStore(int type) : typeStorage(type) {}
    virtual int AddProduct(const Product& product) = 0;
    virtual const std::vector<Product> GetProducts() const = 0;
    virtual ~IProductStore() = default; // {};

    int GetTypeStorage() const {
        return typeStorage;
    }
};

class InMemoryProductStoreList : public IProductStore {
    std::list<Product> products;

public:
    InMemoryProductStoreList(): IProductStore(1) {
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

class InMemoryProductStore : public IProductStore {
    std::vector<Product> products;

public:
    InMemoryProductStore() : IProductStore(2){
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

class FileCSVProductStore : public IProductStore {
    std::string filename;
public:
    FileCSVProductStore(const std::string& file) : IProductStore(3), filename(file) {
        std::cout << "Using File CSV as storage type. file: " << filename << "\n";
    }

    std::string GetFilename() const {
        return filename;
    }

    int AddProduct(const Product& product) override {
        std::ofstream file(GetFilename(), std::ios::app);

        if (file.is_open()) {
            file << product.GetName() << "," << product.GetPrice() << "\n";
            file.close();
            return 1; // Success
        }
        else{
            std::cerr << "Error opening file for writing: " << GetFilename() << "\n";
            return 0; // Failure
        }
    }

    const std::vector<Product> GetProducts() const override {
        std::cout << "Reading products from file: " << GetFilename() << "\n";

        std::ifstream file(GetFilename());
        if(file.is_open()) {
            std::vector<Product> products;

            std::string line;

            while (std::getline(file, line)) {
                size_t commaPos = line.find(',');
                if (commaPos != std::string::npos) {
                    std::string name = line.substr(0, commaPos);
                    int price = std::stoi(line.substr(commaPos + 1));
                 
                    products.emplace_back(name, price);
                }
            }
            file.close();
            return products;
        } else {
            std::cerr << "Error opening file for reading: " << GetFilename() << "\n";
            
            return {}; // return std::vector<Product>{}; // return std::vector<Product>();
        }
    }
};


// Прототипи
void showMainMenu();
Product addProduct();
void showListProducts(const std::vector<Product>& products);

std::unique_ptr<IProductStore> makeStore(int storageType) {
    switch (storageType) {
        case 1:
            return std::make_unique<InMemoryProductStoreList>();
        case 2:
            return std::make_unique<InMemoryProductStore>();
        case 3:
            return std::make_unique<FileCSVProductStore>("products.csv");
        default:
            return std::make_unique<InMemoryProductStore>(); // Default to vector
    }
}

int main(int argc, char* argv[]) {
    
    std::clog << "Application started.\n";

    std::clog << "argc: " << argc << "\n";
    for (int i = 0; i < argc; ++i) {
        std::clog << "argv[" << i << "]: " << argv[i] << "\n";
    }

    std::unique_ptr<IProductStore> store;

    if(argc > 1) {
        std::string storageArg = argv[1];
        if(storageArg == "--type-file-csv")
        {
            std::clog << "Storage type set to File CSV via command line argument.\n";
            store = makeStore(3);
        }
        else {
            std::clog << "Unknown storage argument.\n Aplication will exit.\n";
            std::exit(1);
        }
        std::clog << "Storage argument provided: " << storageArg << "\n";
    } else {
        std::cout << "Select storage type:\n1. List\n2. Vector(Default)\n \n3. File CSV\nChoose an option: ";
        int storageChoice;
        std::cin >> storageChoice;
        
        store = makeStore(storageChoice);
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
