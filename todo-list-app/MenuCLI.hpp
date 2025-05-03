#pragma once

#include <functional>
#include <vector>
#include <string>

struct MenuOption
{
    std::string name;
    std::function<void()> handler;
    bool printHolder = true;
};

class MenuCLI {
    std::vector<MenuOption> menuOptions;
public:
    void show() const;
    void addHandlerMenuOption(const std::string& aName, std::function<void()> aHandler, bool aPrintHolder = true);
private:
    void showMenu() const;
    void handleMenuOption(int aOption) const;

    void ValidateDuplicateOption(const std::string& aName);
};
