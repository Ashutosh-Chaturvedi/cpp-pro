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
    std::string getName() {
        
        return name;
    }

};

int main() {

    std::vector<Account> accounts;
    Account account1("John", 1000, 123456789);
    accounts.push_back(account1);
    std::cout << "Name: " << accounts[0].getName();


}