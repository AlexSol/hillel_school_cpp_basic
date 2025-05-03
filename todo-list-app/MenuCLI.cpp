#include "MenuCLI.hpp"

#include <algorithm>
#include <iostream>
#include <limits>

void MenuCLI::show() const
{
    int indexOption = -1;
    do {
        showMenu();
        std::cin >> indexOption;

        if (std::cin.fail() == false)
        {
            handleMenuOption(indexOption);
        }
        else{
            std::cin.clear(); // скидає помилковий стан
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищає буфер
            std::cout << "Error: Некоректне введення.\n";
        }

    } while (true);
}

void MenuCLI::showMenu() const
{
    std::cout << "\n==== Меню ====\n";

    for (size_t i = 0; i < menuOptions.size(); ++i) {
        std::cout << i << ". " << menuOptions[i].name << "\n";
    }
    
    std::cout << "Виберіть опцію: ";
}

void MenuCLI::addHandlerMenuOption(const std::string& aName, std::function<void()> aHandler, bool aPrintHolder)
{
    ValidateDuplicateOption(aName);
    menuOptions.push_back(MenuOption{aName, aHandler, aPrintHolder});
}

void MenuCLI::ValidateDuplicateOption(const std::string& aName)
{
    const auto found = std::find_if(menuOptions.begin(), menuOptions.end(), [&](const MenuOption& option) {
        return option.name == aName;
    });

    if(found != menuOptions.end())
    {
        std::cout << "Ця опція вже існує!" << std::endl;
        // throw std::runtime_error("Ця опція вже існує!");
    }
}

void MenuCLI::handleMenuOption(int aIndexOption) const
{
    if (aIndexOption < 0 || aIndexOption >= menuOptions.size()) {
        std::cout << "Невірна опція" << std::endl;
        return;
    }

    const MenuOption& option = menuOptions[aIndexOption];
    
    if(option.printHolder)
    {
        std::cout << "\n----" <<  option.name << "----\n" << std::endl;
    }

    option.handler();
}