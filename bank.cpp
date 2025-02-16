#include<iostream>
#include<vector>
#include<string>
#include<limits>

template <typename T>
T getValidatedInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        } else {
            return value;
        }
    }
}

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
    int choice = getValidatedInput<int> ("Choose: ");

    switch (choice) {
        case 1:{
        double credit = getValidatedInput<double>("Enter the amount to deposit: ");
        acc.deposit(credit);
        break;
        }
        case 2:{
        double debit = getValidatedInput<double>("Enter the amount to withdraw: ");
        acc.withdraw(debit);
        break;
        }
        case 3:{
        std::cout << "Your current balance is: " << acc.viewBalance() << std::endl;
        break;
        }
        case 4:
        return;
        
        default:
        std::cout << "Invalid choice. Please choose a valid option." << std::endl;
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
    int choice = getValidatedInput<int>("Account Number: ");

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
    
    int accountNumber = getValidatedInput<int>("Enter the account number: ");

    std::string name;
    std::cout << "Enter the name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    double balance = getValidatedInput<double>("Enter the balance: ");
    
    Account newAccount(name, balance, accountNumber);
    accounts.push_back(newAccount);
}

void menu(std::vector<Account>& accounts) {
    using namespace std;
    cout << "\n\tBANK\n";
    cout << "1. Create Account\n";
    cout << "2. Accounts\n";
    cout << "3. Exit\n\n";
    int n = getValidatedInput<int>("Choose from the above options: ");
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
