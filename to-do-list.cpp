#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<windows.h>

void print(std::vector<std::string> &list);

void del(std::vector<std::string> &list){

    std::cout << "Choose which task to delete. " << std::endl;
    print(list);
    int i;
    std::cin >> i;
    list.erase(list.begin() + i - 1);
    char c;
    std::cout << "Want to do it again? (Y/N)" << std::endl;
    std::cin >> c;
    if(c == 'Y'){
        del(list);
    } else return;
    
}

void enter(std::vector<std::string> &list) {
    std::cout << std::endl;
    std::string Item;
    std::cout << "Enter: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin , Item);
    list.push_back(Item);

    int n;
    std::cout << "Want to enter more? (If yes then press 1.): ";
    while (!(std::cin >> n)) {
        std::cout << "Invalid input. Please enter 1 for yes or 0 for no: ";
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline left in the buffer

    if (n == 1) {
        enter(list); // Consider replacing with a loop to avoid recursion
    }
}

void print(std::vector<std::string> &list){

    std::cout << std::endl;
    std::cout << "YOUR LIST: " << std::endl;
    int n = list.size();
    for(int i = 0; i < n ; i++){
        std::cout << i+1 << ". " << list[i] << '\n';
    }
}

void menu(std::vector<std::string> &list){
    // sleep(5);
    
    std::cout << "\nChoose from the following Operations: \n" ;
    int n ;
    std::cout << "1. Enter new task \n";
    std::cout << "2. Delete the task \n";
    std::cout << "3. Show the whole list \n";
    std::cout << "Option: ";
    std::cin >> n;
    if(n == 1) {
        enter(list);
        menu(list);
    }
    if(n == 2) {
        del(list);
        menu(list);
    }
    if(n == 3){
        print(list);
        menu(list);
    }

}

int main(){
    std::cout << "TO-DO List" << std::endl;
    std::vector<std::string> list;
    menu(list);
}