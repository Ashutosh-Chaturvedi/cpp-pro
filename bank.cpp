#include<fstream> 
#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<sstream>

template <typename T>
T getValidatedInput(const std::string& prompt, bool mustBePositive = false) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || (mustBePositive && value < 0)) { 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid " 
                      << (mustBePositive ? "positive " : "") << "number." << std::endl;
        } else {
            return value;
        }
    }
}
class Account {
    std::string name;
    std::string type;
    long long accountNumber;
    double balance;
    int pin;

    public:
    Account() = default;

    Account(std::string n, double b, long long an, int t, int p) {
        type = (t == 0) ? "Saving" : (t == 1) ? "Current" : "Unknown";
        name = n;
        balance = b;
        accountNumber = an;
        pin = p;
    }

    void deposit(double amount) {
        
        balance += amount;

    }
    void withdraw(double amount) {
        
        if (amount > this->balance) {
            std::cout << "Insufficient funds" << std::endl;
        }
        else {
            balance -= amount;
        }
        
    }
    std::string getType() const {
        return type;
    }
    long long getAccountNumber() const {
        return accountNumber;
    }
    int getPin() const {
        return pin;
    }
    std::string getName() const {        
        return name;
    }
    double viewBalance() const {
        return balance;
    }
};

void updateFile(std::vector<Account> &accounts) {
    std::ofstream file("accounts.txt", std::ios::trunc);
    if (file.is_open()) {
        for (const auto& acc : accounts) {
            file << acc.getAccountNumber() << "," << acc.getName() << "," << acc.viewBalance() << "," << acc.getType() << "," << acc.getPin() << std::endl;
        }
        file.close();
    } else {
        std::cout << "Error: Could not update file!" << std::endl;
    }
}

void operations(Account& acc, std::vector<Account>& accounts) {
    std::cout << "Choose from the below options:\n";
    std::cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n";
    
    int choice = getValidatedInput<int>("Choose: ", true);

    switch (choice) {
        case 1: {
            double credit = getValidatedInput<double>("Enter the amount to deposit: ", true);
            acc.deposit(credit);
            updateFile(accounts); 
            break;
        }
        case 2: {
            double debit = getValidatedInput<double>("Enter the amount to withdraw: ", true);
            acc.withdraw(debit);
            updateFile(accounts);  
            break;
        }
        case 3: {
            std::cout << "Your current balance is: " << acc.viewBalance() << std::endl;
            break;
        }
        case 4:
            return;
        default:
            std::cout << "Invalid choice. Please choose a valid option.\n";
    }
    operations(acc, accounts);    
}


void viewAll(std::vector<Account>& accounts) {
    std::cout << "\n\tACCOUNTS\n";
    
    for (size_t i = 0; i < accounts.size(); i++) {    
        std::cout << "\nAccount Number: " << accounts[i].getAccountNumber() << std::endl;
        std::cout << "   Account Type: " << accounts[i].getType() << std::endl;
        std::cout << "   Name: " << accounts[i].getName() << std::endl;
        std::cout << "   Balance: " << accounts[i].viewBalance() << std::endl;
    }

    std::cout << "\nIf you want to perform any operation on any of these accounts, choose the account number and press enter (or press 0 to exit).\n";
    int choice = getValidatedInput<int>("Account Number: ", true);

    bool found = false;
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == choice) {
            found = true;
            int attempts = 3;
            while (attempts--) {
                int pass = getValidatedInput<int>("Enter the PIN: ", true);
                if (pass == accounts[i].getPin()) { 
                    std::cout << "Access granted!\n";
                    operations(accounts[i], accounts);
                    return;
                } else {
                    std::cout << "Incorrect PIN! Attempts left: " << attempts << "\n";
                }
            }
            std::cout << "Too many incorrect attempts! Returning to menu.\n";
            return;
        }
    }
    if (!found) std::cout << "Account not found! Returning to menu.\n";

}


void addNew(std::vector<Account>& accounts) {
    
    int accountNumber = getValidatedInput<int>("Enter the account number: ",true);

    std::string name;
    std::cout << "Enter the name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    double balance = getValidatedInput<double>("Enter the balance: ",true);
    int type = getValidatedInput<int>("Choose 0 for saving account & 1 for current: ",true);
    int pin = getValidatedInput<int>("Enter the pin: ",true);
    Account newAccount(name, balance, accountNumber, type, pin);
    accounts.push_back(newAccount);

    //Accounts detail in external file
    std::ofstream file("accounts.txt", std::ios::app);
    if (file.is_open()){
        file << accountNumber << "," << name << "," << balance << "," << type << "," << pin << "\n";
        file.close();
    } else {
        std::cout << "Error: Could not save account!" << std::endl;
    }
}

void menu(std::vector<Account>& accounts) {
    using namespace std;
    cout << "\n\tBANK\n";
    cout << "1. Create Account\n";
    cout << "2. Accounts\n";
    cout << "3. Exit\n\n";
    int n = getValidatedInput<int>("Choose from the above options: ", true);
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

void loadAccounts(std::vector<Account>& accounts) {
    std::ifstream file("accounts.txt");
    if (!file.is_open()) {
        std::cout << "No previous accounts found!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {  
        std::cout << "Reading line: " << line << std::endl;  // Debugging

        std::stringstream ss(line);
        std::string accountNumberStr, name, balanceStr, typeStr, pinStr;

        if (!std::getline(ss, accountNumberStr, ',') ||
            !std::getline(ss, name, ',') ||
            !std::getline(ss, balanceStr, ',') ||
            !std::getline(ss, typeStr, ',') ||
            !std::getline(ss, pinStr, ',')) {
            std::cout << "Error: Malformed line detected!" << std::endl;
            continue;  // Skip this line
        }

        try {
            long long accountNumber = std::stoll(accountNumberStr);
            double balance = std::stod(balanceStr);
            int pin = std::stoi(pinStr);

            // Convert type string to integer (0 for Saving, 1 for Current)
            int type;
            if (typeStr == "Saving") {
                type = 0;
            } else if (typeStr == "Current") {
                type = 1;
            } else {
                std::cout << "Error: Unknown account type '" << typeStr << "'\n";
                continue; // Skip this invalid entry
            }

            accounts.push_back(Account(name, balance, accountNumber, type, pin));
        } catch (const std::exception& e) {
            std::cout << "Error parsing line: " << line << " - " << e.what() << std::endl;
        }
    }

    file.close();
}

int main() {
    std::vector<Account> accounts;
    loadAccounts(accounts);
    menu(accounts);
}
