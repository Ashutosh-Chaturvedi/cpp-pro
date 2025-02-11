#include<iostream>
#include<vector>

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
    for(int i = 0; i < accounts.size(); i++){
        std::cout << "Account Number: " << accounts[i].getAccountNumber() << std::endl;
        std::cout << "Name: " << accounts[i].getName() << std::endl;
        std::cout << "Balance: " << accounts[i].viewBalance() << std::endl;
    }
}

void addNew(std::vector<Account>& accounts) {
    
}

void menu(std::vector<Account>& accounts){
    using namespace std;
    cout << "\t\tBANK\n";
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
