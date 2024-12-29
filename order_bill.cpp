#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

void orderSummary(std::vector<int> &orders,std::vector<std::string> & menuList, std::vector<int> &price, std::vector<int>& cost, std::vector<int>& quantity){
    std::cout << "\n\n \tORDER SUMMARY \n";
    std::cout << "Code\tItem\t Quantity \tRate\t Cost\n";

    int totalQuantity = 0;
    int totalCost = 0;

    for(int i = 0; i < orders.size(); i++){
        int index = orders[i];
        totalCost = totalCost + (price[index] * quantity[i]);
        totalQuantity = totalQuantity + quantity[i];
        std::cout << " "<< index + 1 << "     " << menuList[index] << "\t\t" << quantity[i] << "\t$" << price[index] << "\t$" << quantity[i] * price[index] << '\n';
    }

    std::cout << "\nTotal\t\t\t" << totalQuantity << "\t\t$" << totalCost << '\n';
    std::cout << std::endl;
}

void order(int b, std::vector<std::string> & menuList, std::vector<int> &price, std::vector<int> &orders, std::vector<int>& cost, std::vector<int>& quantity)
{
    if(b == 0) return;
    int n;
    std::cout << "\nEnter the code for what you want to order: ";
    std::cin >> n;
    if(n > menuList.size()){
        std::cout << "Invalid code. Please enter a valid code.\n";
        order(b, menuList, price, orders, cost, quantity);
        return;
    }

    int quan;
    std::cout << "Enter quantity of " << menuList[n-1] << " you want to order: ";
    std::cin >> quan;
    if(n > 0 && n <= price.size()) {
        std::cout << "You have ordered " << quan << " " << menuList[n-1] << " for " << price[n-1] <<"$ each "<< '\n';
        orders.push_back(n-1);
        quantity.push_back(quan);
        b--;
    } else {
        std::cout << "Invalid Option \n Try again\n";
    }
    order(b,menuList, price, orders, cost, quantity);
}

void menu(std::vector<std::string> & menuList, std::vector<int> &price) {
    std::cout << "Code\t Item \t Price \n";
    for(int i = 0; i < price.size(); i++){
        std::cout << " " << i+1 << ".\t" << menuList[i] << " \t $" << price[i] << '\n';
    } 
    int n;
    std::cout << "\nEnter the number of different dishes you want to order: ";
    std::cin >> n;
    std::vector<int> orders;
    std::vector<int> cost;
    std::vector<int> quantity;
    order(n , menuList, price, orders, cost, quantity);
    orderSummary(orders, menuList, price, cost, quantity);

}
int main(){
    std::cout << "WELCOME \n";
    
    //Using vector of string to assign menu items
    std::vector<std::string> items = {"Pizza" , "Burger", "Fries", "Momos", "Salad"};

    //Using vector of int to assign prices
    std::vector<int> prices = {120, 80, 40, 60, 100};
    
    //Menu fuction call
    menu(items, prices);
    return 0;

}