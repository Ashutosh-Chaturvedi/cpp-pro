#include"color.h"
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
#include<thread>
#define PIN 1860

void printWithDelay(const std::string& text, const std::string& formats = RESET, int delay = 30) {
    std::cout << formats; 
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << RESET;
}

template <typename T>
T getValidatedInput(const std::string& prompt, bool mustBePositive = false, const std::string& color = RESET) {
    T value;
    while (true) {
        printWithDelay(prompt, color);
        std::cin >> value;

        if (std::cin.fail() || (mustBePositive && value < 0)) { 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid " << (mustBePositive ? "positive " : "") << "number." << std::endl;
        } else {
            return value;
        }
    }
}

void progressBar() {
    std::cout << "Processing: [" << BLUE;
    
    for (int i = 0; i < 20; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "#";
        std::cout.flush(); 
    }
    std::cout << RESET << "] Done!\n";
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

    std::string getType() const { return type; }
    long long getAccountNumber() const { return accountNumber; }
    int getPin() const { return pin; }
    std::string getName() const { return name; }
    double viewBalance() const { return balance; }
};

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
    file << type << "ed  " << amount << " \t" << account.viewBalance() <<"\t" << Date() << "  " << Time() << std::endl;

}

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
    std::cout << BOLD_MAGENTA << "\nChoose from the below options:\n" << RESET;
    std::cout << GREEN << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Bank Statement\n0. Exit\n" << RESET;
    
    int choice = getValidatedInput<int>("Choose: ", true, ITALIC_YELLOW);

    switch (choice) {
        case 1: {
            double credit = getValidatedInput<double>("Enter the amount to deposit: ", true, ITALIC_YELLOW);
            acc.deposit(credit);
            updateFile(accounts); 
            record(acc, "Credit" , credit);
            progressBar();
            std::cout << BOLD_GREEN << "Deposit successful!" << std::endl << RESET;
            break;
        }
        case 2: {
            double debit = getValidatedInput<double>("Enter the amount to withdraw: ", true, ITALIC_YELLOW);
            acc.withdraw(debit);
            updateFile(accounts);  
            record(acc, "Debit", debit);
            progressBar();
            std::cout << BOLD_GREEN << "Withdrawal successful!" << std::endl << RESET;
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
    operations(acc, accounts); 
}

void viewAll(std::vector<Account>& accounts) {
    printWithDelay("\n\tACCOUNTS\n",BOLD_RED);

    for (size_t i = 0; i < accounts.size(); i++) {    
        printWithDelay( "\nAccount Number: ", BLUE, 10 );
        std::cout << accounts[i].getAccountNumber() << std::endl;
        printWithDelay("Account Type: ",BLUE, 10);
        std::cout << accounts[i].getType() << std::endl;
        printWithDelay("Name: ",BLUE, 10);
        std::cout << accounts[i].getName() << std::endl;
        printWithDelay("Balance: ",BLUE, 10);
        std::cout << accounts[i].viewBalance() << std::endl;
    }

    printWithDelay("\nEnter an account number to proceed or 0 to exit..\n",ITALIC_YELLOW);
    int choice = getValidatedInput<int>("Account Number: ", true,ITALIC_YELLOW);

    bool found = false;
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == choice) {
            found = true;
            int attempts = 3;
            while (attempts--) {
                int pass = getValidatedInput<int>("Enter the PIN: " , true, BOLD_CYAN);
                if (pass == accounts[i].getPin()) { 
                    std::cout << BOLD_GREEN << "Access granted!\n" << RESET;
                    operations(accounts[i], accounts);
                    return;
                } else {
                    std::cout << BOLD_RED << "Incorrect PIN! Attempts left: " << attempts << "\n" << RESET;
                }
            }
            std::cout << BOLD_RED << "Too many incorrect attempts! Returning to menu.\n" << RESET;
            return;
        }
    }
    if (!found) std::cout << BOLD_RED << "Account not found! Returning to menu.\n" << RESET;
}

void addNew(std::vector<Account>& accounts) {

    int accountNumber;

    int n = accounts.size();
    if(n == 0){
        accountNumber = 42058001;
    } else {
        accountNumber = accounts[n-1].getAccountNumber() + 1;
    }
    
    std::string name;
    printWithDelay("Enter the name: ");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    
    double balance = getValidatedInput<double>("Enter the balance: ",true);
    int type = getValidatedInput<int>("Choose 0 for saving account & 1 for current: ",true);
    
    std::string typeStr = (type == 0) ? "Saving" : "Current";
    int pin = getValidatedInput<int>("Enter the pin: ",true);
    printWithDelay("\nAccount Created Successfully!");
   
    Account newAccount(name, balance, accountNumber, type, pin);
    accounts.push_back(newAccount);
  
    std::ofstream his(name + ".txt",std::ios::app);
    if(his.is_open()){
        his << "Type : " << typeStr << "\n";
        his << "Account Number: " << accountNumber << "\n";
        his << "Date: " << Date() << std::endl;
        his << "Time: " << Time() << std::endl;
        his << "Deposited: " << balance << "\n";
        his << "\n Type    Amount      Balance     Date    Time\n";
    }

    std::ofstream file("accounts.txt", std::ios::app);
    if (file.is_open()){
        file << accountNumber << "," << name << "," << balance << "," << typeStr << "," << pin << "\n";
        file.close();
    } else {
        std::cout << "Error: Could not save account!" << std::endl;
    }
}

void menu(std::vector<Account>& accounts) {
    using namespace std;
    while(true){
        printWithDelay("\n=====BANK=====\n",BOLD_BLUE) ;
        printWithDelay("1. Create Account\n",GREEN);
        printWithDelay("2. Accounts\n",GREEN);
        printWithDelay("3. Exit\n\n",GREEN);
        
        int n = getValidatedInput<int>("Choose from the above options: ", true,ITALIC_YELLOW);
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

        if (!std::getline(ss, accountNumberStr, ',') ||
            !std::getline(ss, name, ',') ||
            !std::getline(ss, balanceStr, ',') ||
            !std::getline(ss, typeStr, ',') ||
            !std::getline(ss, pinStr, ',')) {
            std::cout << "Error: Malformed line detected!" << std::endl;
            continue; 
        }

        try {
            long long accountNumber = std::stoll(accountNumberStr);
            double balance = std::stod(balanceStr);
            int pin = std::stoi(pinStr);

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

bool validation(int & password){

    int attempts = 3;
    while (attempts--) {
        int pass = getValidatedInput<int>("Enter the PIN: " , true, BOLD_CYAN);
        if (pass == password) { 
            std::cout << BOLD_GREEN << "Access granted!\n" << RESET;
            return 1;
        } else {
            std::cout << BOLD_RED << "Incorrect PIN! Attempts left: " << attempts << "\n" << RESET;
        }
    } 
    std::cout << BOLD_RED << "Too many incorrect attempts! Returning to menu.\n" << RESET;
    return 0;

}

int main() {
    printWithDelay("Loading banking system...\n");
    printWithDelay("Press Enter to continue.....");
    std::cin.get();  
    system(CLEAR_SCREEN);
    int pin = PIN;
    if(!validation(pin)) return 1;
    system(CLEAR_SCREEN);
    std::vector<Account> accounts;  
    loadAccounts(accounts);        
    menu(accounts);                
}