#include<iostream>
#include<vector>
#include<string>
#include<limits>

void enter(std::vector<std::string> &list) {
    std::cout << std::endl;
    std::string Item;
    std::cout << "Enter: ";
    std::getline(std::cin, Item);
    list.push_back(Item);

    int n;
    std::cout << "Want to enter more? (If yes then press 1.): ";
    while (!(std::cin >> n)) {
        std::cout << "Invalid input. Please enter 1 for yes or 0 for no: ";
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline left in the buffer

    if (n == 1) {
        enter(list); // Consider replacing with a loop to avoid recursion
    }
}
void print(std::vector<std::string> &list){
    std::cout << std::endl;
    int n = list.size();
    for(int i = 0; i < n ; i++){
        std::cout << list[i] << '\n';
    }
}

int main(){
    std::cout << "TO-DO List" << std::endl;
    std::vector<std::string> list;
    std::cout << "Chose from the following Operations: \n" ;
    int n ;
    std::cout << "1. Enter new task \n";
    std::cout << "2. Delete the task \n";
    std::cout << "3. Show the whole list \n";
    std::cin >> n;
    if(n == 1) enter(list);
    print(list);

}