#include<iostream>
#include<vector>
#include<string>

class Account {
    std::string name;
    long long accountNumber;
    double balance;

    public:
    Account(std::string n, double b, long long an) {
        name = n;
        balance = b;
        accountNumber = an;
    }

    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds" << std::endl;
        }
        else {
            balance -= amount;
        }
    }
    long long getAccountNumber() {
        return accountNumber;
    }
    std::string getName() {        
        return name;
    }
    double viewBalance() {
        return balance;
    }
};

void viewAll(std::vector<Account>& accounts) {
    std::cout << "\n\tACCOUNTS\n";
    for(int i = 0; i < accounts.size(); i++){    
        std::cout << "\n1. Account Number: " << accounts[i].getAccountNumber() << std::endl;
        std::cout << "   Name: " << accounts[i].getName() << std::endl;
        std::cout << "   Balance: " << accounts[i].viewBalance() << std::endl;
    }
}

void addNew(std::vector<Account>& accounts) {
    std::string name;
    double balance;
    std::cout << "Enter the name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter the balance: ";
    std::cin >> balance;
    Account newAccount(name, balance, 32412313);
    accounts.push_back(newAccount);
}

void menu(std::vector<Account>& accounts) {
    using namespace std;
    cout << "\n\tBANK\n";
    cout << "1. Create Account\n";
    cout << "2. Accounts\n";
    cout << "3. Exit\n\n";
    int n;
    cout << "Choose from above options: ";
    cin >> n;
    switch (n) {
        case 1:
        addNew(accounts);
        break;
        case 2:
        viewAll(accounts);
        break;
        case 3:
        return;
    }
    menu(accounts);
}

int main() {
    std::vector<Account> accounts;
    menu(accounts);
}
