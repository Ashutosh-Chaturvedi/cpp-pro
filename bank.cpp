#include<iostream>
#include<vector>
#include<string>
#include<limits>

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

void operations(Account & acc) {
    std::cout << "Choose from the below options:" << std::endl;
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Check Balance" << std::endl;
    std::cout << "4. Exit" << std::endl;
    int choice;
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.clear();  
        std::cin.ignore(1000, '\n');  
    }
    else {
        switch (choice) {
            case 1:
            std::cout << "Enter the amount to deposit: ";
            double amount;
            std::cin >> amount;
            acc.deposit(amount);
            break;
            case 2:
            std::cout << "Enter the amount to withdraw: ";
            std::cin >> amount;
            acc.withdraw(amount);
            break;
            case 3:
            std::cout << "Your current balance is: " << acc.viewBalance() << std::endl;
            break;
            case 4:
            return;
            default:
            std::cout << "Invalid choice. Please choose a valid option." << std::endl;
        }
    }
    operations(acc);    
}

void viewAll(std::vector<Account>& accounts) {
    std::cout << "\n\tACCOUNTS\n";
    for(int i = 0; i < accounts.size(); i++){    
        std::cout << "\n1. Account Number: " << accounts[i].getAccountNumber() << std::endl;
        std::cout << "   Name: " << accounts[i].getName() << std::endl;
        std::cout << "   Balance: " << accounts[i].viewBalance() << std::endl;
    }
    std::cout << "If you want to perform any operation on any of these account choose the account number and press enter.(else press 0)\n";
    int choice;
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        } else {
            break;
        }
    }
    if(choice != 0){
        for(int i = 0; i < accounts.size(); i++){
            if(accounts[i].getAccountNumber() == choice){
                operations(accounts[i]);
                break;
            }
        }
    }

}

void addNew(std::vector<Account>& accounts) {
    std::cout << "\nEnter the account number: ";
    int accountNumber;
    std::cin >> accountNumber;
    std::string name;
    double balance;
    std::cout << "Enter the name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter the balance: ";
    std::cin >> balance;
    Account newAccount(name, balance, accountNumber);
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
