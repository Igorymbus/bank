#include <iostream>

class BankAccount {
private:
    int accountNumber; 
    double balance; 
    double interestRate; 

public:
    BankAccount(int accountNumber, double initialBalance) {
        this->accountNumber = accountNumber;
        this->balance = initialBalance;
        this->interestRate = 0.0; 
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Депозит в размере $" << amount << " успешно.\n";
        }
        else {
            std::cout << "Недействительная сумма депозита.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Изъятие $" << amount << " успешно.\n";
        }
        else {
            std::cout << "Неверная сумма вывода или недостаточно средств.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    double getInterest() const {
        return balance * interestRate * (1.0 / 12.0);
    }

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
        std::cout << "Передача $" << amount << " успешно.\n";
        return true;
    }
    else {
        std::cout << "Неверная сумма вывода или недостаточно средств.\n";
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
   
    BankAccount account1(12345, 1000.0);
    BankAccount account2(54321, 500.0);
    account1.deposit(200.0);
    account1.withdraw(50.0);
    account2.deposit(300.0);
    transfer(account1, account2, 150.0);
    std::cout << "Баланс счета 1: $" << account1.getBalance() << std::endl;
    std::cout << "Баланс счета 2: $" << account2.getBalance() << std::endl;

    return 0;
}



