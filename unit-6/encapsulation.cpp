#include <iostream>
#include <string>

class BankAccount {
private:
    double balance; // Приватне поле

public:
    BankAccount(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            std::cout << "Invalid initial balance, set to 0." << std::endl;
        }
    }

    // Геттер
    double getBalance() const {
        return balance;
    }

    // Сеттер
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds or invalid amount!" << std::endl;
        }
    }
};

int main() {
    BankAccount account(100.0);
    account.deposit(50);
    account.withdraw(30);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    return 0;
}
