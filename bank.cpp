#include<fstream> 
#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<sstream>
#include<random>
#include<chrono>
#include<ctime>
#include<iomanip>

// Template function to get and validate user input
// Returns only when valid input is received
template <typename T>
T getValidatedInput(const std::string& prompt, bool mustBePositive = false) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        // Check for invalid input or negative numbers when positive is required
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

std::string Date(){
    auto now = std::chrono::system_clock::now();    
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_c);
    std::ostringstream oss;
    oss << std::put_time(local_time, "%Y-%m-%d"); 
    return oss.str();
}

std::string Time(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_c);
    std::ostringstream oss;
    oss << std::put_time(local_time, "%H:%M:%S");
    return oss.str();
}
// Account class to manage bank account information and operations
class Account {
    // Private member variables
    std::string name;        // Account holder's name
    std::string type;        // Account type (Saving/Current)
    long long accountNumber; // Account number
    double balance;         // Current balance
    int pin;               // PIN for account access

    public:
    // Default constructor
    Account() = default;

    // Parameterized constructor
    Account(std::string n, double b, long long an, int t, int p) {
        type = (t == 0) ? "Saving" : (t == 1) ? "Current" : "Unknown";
        name = n;
        balance = b;
        accountNumber = an;
        pin = p;
    }

    // Method to deposit money into account
    void deposit(double amount) {
        balance += amount;
    }

    // Method to withdraw money from account
    void withdraw(double amount) {
        if (amount > this->balance) {
            std::cout << "Insufficient funds" << std::endl;
        }
        else {
            balance -= amount;
        }
    }

    // Getter methods
    std::string getType() const { return type; }
    long long getAccountNumber() const { return accountNumber; }
    int getPin() const { return pin; }
    std::string getName() const { return name; }
    double viewBalance() const { return balance; }
};

//Function to view Transaction History
void TransactionHistory(Account & account) {

    std::ifstream file(account.getName() + ".txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "File not found" << std::endl;
    }

}

void record(Account & account, std::string type, double amount) {
    
    std::ofstream file(account.getName() + ".txt", std::ios_base::app);
    file << type << "," << amount << "," << account.viewBalance() <<"," << Date() << "," << Time() << std::endl;

}

// Function to update the accounts file after any transaction
void updateFile(std::vector<Account> &accounts) {
    std::ofstream file("accounts.txt", std::ios::trunc);  // Open file in truncate mode
    if (file.is_open()) {
        // Write each account's details to file
        for (const auto& acc : accounts) {
            file << acc.getAccountNumber() << "," << acc.getName() << "," << acc.viewBalance() << "," << acc.getType() << "," << acc.getPin() << std::endl;
        }
        file.close();
    } else {
        std::cout << "Error: Could not update file!" << std::endl;
    }
}

// Function to handle account operations (deposit, withdraw, balance check)
void operations(Account& acc, std::vector<Account>& accounts) {
    std::cout << "\nChoose from the below options:\n";
    std::cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Bank Statement\n0. Exit\n";
    
    int choice = getValidatedInput<int>("Choose: ", true);

    switch (choice) {
        case 1: {
            double credit = getValidatedInput<double>("Enter the amount to deposit: ", true);
            acc.deposit(credit);
            updateFile(accounts); 
            record(acc, "Credit" , credit);
            std::cout << "Deposit successful!" << std::endl;
            break;
        }
        case 2: {
            double debit = getValidatedInput<double>("Enter the amount to withdraw: ", true);
            acc.withdraw(debit);
            updateFile(accounts);  
            record(acc, "Debit", debit);
            std::cout << "Withdrawal successful!" << std::endl;
            break;
        }
        case 3: {
            std::cout << "Your current balance is: " << acc.viewBalance() << std::endl;
            break;
        }
        case 4:
            TransactionHistory(acc);
          
        case 0:
            return;
        default:
            std::cout << "Invalid choice. Please choose a valid option.\n";
    }
    operations(acc, accounts);  // Recursive call for continuous operation
}

// Function to view all accounts and perform operations on selected account
void viewAll(std::vector<Account>& accounts) {
    std::cout << "\n\tACCOUNTS\n";
    
    // Display all accounts
    for (size_t i = 0; i < accounts.size(); i++) {    
        std::cout << "\nAccount Number: " << accounts[i].getAccountNumber() << std::endl;
        std::cout << "Account Type: " << accounts[i].getType() << std::endl;
        std::cout << "Name: " << accounts[i].getName() << std::endl;
        std::cout << "Balance: " << accounts[i].viewBalance() << std::endl;
    }

    std::cout << "\nEnter an account number to proceed or 0 to exit..\n";
    int choice = getValidatedInput<int>("Account Number: ", true);

    // Search for selected account and verify PIN
    bool found = false;
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == choice) {
            found = true;
            int attempts = 3;  // Allow 3 PIN attempts
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

// Function to add a new account
void addNew(std::vector<Account>& accounts) {
    // Get account details from user
    int accountNumber;

    int n = accounts.size();
    if(n == 0){
        accountNumber = 42058001;
    } else {
        accountNumber = accounts[n-1].getAccountNumber() + 1;
    }
    
    std::string name;
    std::cout << "Enter the name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    
    double balance = getValidatedInput<double>("Enter the balance: ",true);
    int type = getValidatedInput<int>("Choose 0 for saving account & 1 for current: ",true);
    
    std::string typeStr = (type == 0) ? "Saving" : "Current";
    int pin = getValidatedInput<int>("Enter the pin: ",true);
    
    // Create and store new account
    Account newAccount(name, balance, accountNumber, type, pin);
    accounts.push_back(newAccount);
  
    std::ofstream his(name + ".txt",std::ios::app);
    if(his.is_open()){
        his << "Type : " << typeStr << "\n";
        his << "Account Number: " << accountNumber << "\n";
        his << "Date: " << Date() << std::endl;
        his << "Time: " << Time() << std::endl;
        his << "Deposited: " << balance << "\n";
    }

    // Save account details to file
    std::ofstream file("accounts.txt", std::ios::app);
    if (file.is_open()){
        file << accountNumber << "," << name << "," << balance << "," << typeStr << "," << pin << "\n";
        file.close();
    } else {
        std::cout << "Error: Could not save account!" << std::endl;
    }
}

// Main menu function
void menu(std::vector<Account>& accounts) {
    using namespace std;
    while(true){
        cout << "\n=====BANK=====\n";
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
    }
}

// Function to load existing accounts from file
void loadAccounts(std::vector<Account>& accounts) {
    std::ifstream file("accounts.txt");
    if (!file.is_open()) {
        std::cout << "No previous accounts found!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string accountNumberStr, name, balanceStr, typeStr, pinStr;

        // Parse CSV format
        if (!std::getline(ss, accountNumberStr, ',') ||
            !std::getline(ss, name, ',') ||
            !std::getline(ss, balanceStr, ',') ||
            !std::getline(ss, typeStr, ',') ||
            !std::getline(ss, pinStr, ',')) {
            std::cout << "Error: Malformed line detected!" << std::endl;
            continue; 
        }

        try {
            // Convert strings to appropriate data types
            long long accountNumber = std::stoll(accountNumberStr);
            double balance = std::stod(balanceStr);
            int pin = std::stoi(pinStr);

            // Determine account type
            int type;
            if (typeStr == "Saving") {
                type = 0;
            } else if (typeStr == "Current") {
                type = 1;
            } else {
                std::cout << "Error: Unknown account type '" << typeStr << "'\n";
                continue;
            }

            accounts.push_back(Account(name, balance, accountNumber, type, pin));
        } catch (const std::exception& e) {
            std::cout << "Error parsing line: " << line << " - " << e.what() << std::endl;
        }
    }

    file.close();
}

// Main function
int main() {
    std::vector<Account> accounts;  // Vector to store all accounts
    loadAccounts(accounts);         // Load existing accounts from file
    menu(accounts);                 // Start the program
}