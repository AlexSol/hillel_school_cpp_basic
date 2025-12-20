#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "Product.hpp"

int main() {
    std::vector<std::string> names;
    std::vector<double> prices;

    int menu_index = 0;

    while (true) {
        std::cout <<"Main Menu:\n"
                    "----------------\n"
                    "1. Add product\n"
                    "2. List products\n"
                    "3. Remove product\n"
                    "0. Exit\n"
                    "----------------\n"
                    "Enter menu option: ";

        if (!(std::cin >> menu_index)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }
        
        if (menu_index == 1) {
            std::cout << "---- Add product ----\n";

            std::string name;
            double price;
            
            std::cout << "Enter product name: ";
            std::cin >> name;
            std::cout << "Enter price: ";
            std::cin >> price;

            names.push_back(name);
            prices.push_back(price);
        }
        else if (menu_index == 2) {
            std::cout << "---- List products ----\n";
            
            if(names.empty()){
                std::cout << "No products.\n";
            }
            else {
                for (size_t iter = 0, indexProduct = 1; iter < names.size(); ++iter, ++indexProduct) {
                    std::cout << indexProduct << ". " << names[iter] << " - $" << prices[iter] << "\n";
                }
            }
            std::cout << "\n";
        }
        else if (menu_index == 3) {
            std::cout << "---- Remove product ----\n";
            
            if(names.empty()){
                std::cout << "No products to remove.\n\n";
                continue;
            }

            size_t index_to_remove;
            std::cout << "Enter product index to remove: ";
            std::cin >> index_to_remove;

            if (index_to_remove < 1 || index_to_remove > names.size()) {
                std::cout << "Invalid index.\n\n";
                continue;
            }

            names.erase(names.begin() + (index_to_remove - 1));
            prices.erase(prices.begin() + (index_to_remove - 1));

            std::cout << "Product removed.\n\n";
        }
        else if (menu_index == 0) {
            std::cout << "\n\nExiting program.\n";
            break;
        }
        else {
            std::cout << "Invalid menu option. Please try again.\n\n";
        }
    };

    return 0;
}