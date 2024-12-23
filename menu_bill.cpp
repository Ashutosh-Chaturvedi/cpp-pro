#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

void orderSummary(std::vector<int> &orders,std::vector<std::string> & menuList, std::vector<int> &price){
    std::cout << "\n\n \tORDER SUMMARY \n";
    std::cout << "Code\tItem\t Quantity \tPrice\n";
    sort(orders.begin(), orders.end());
    std::vector<int> quantity = orders;
    quantity.push_back(orders[0]);

    for(int i = 1; i < orders.size(); i++){
        int count = 1;
        if(orders[i] == orders[i - 1]){
            count++;
            continue;
        }
    }

    for(int i = 0; i < orders.size(); i++){
        int index = orders[i];
        std::cout << " "<< index + 1 << "     " << menuList[index] << "\t\t" << "1 \t" << price[index] << '\n';
    }

}

void order(int b, std::vector<std::string> & menuList, std::vector<int> &price, std::vector<int> &orders )
{
    if(b == 0) return;
    int n;
    std::cout << "Enter the code for what you want to order: ";
    std::cin >> n;
    if(n > 0 && n <= price.size()) {
        std::cout << "You have ordered " << menuList[n-1] << " for " << price[n-1] << '\n';
        orders.push_back(n-1);
        b--;
    } else {
        std::cout << "Invalid Option \n Try again\n";
    }
    order(b,menuList, price, orders);
    orderSummary(orders, menuList, price);
}

void menu(std::vector<std::string> & menuList, std::vector<int> &price) {
    std::cout << "Code\t Item \t Price \n";
    for(int i = 0; i < price.size(); i++){
        std::cout << " " << i+1 << ".\t" << menuList[i] << " \t  " << price[i] << '\n';
    } 
    int n;
    std::cout << "Enter the number of the dish you want to order: ";
    std::cin >> n;
    std::vector<int> orders;
    order(n , menuList, price, orders);
    orderSummary(orders, menuList, price);

}
int main(){
    std::cout << "WELCOME \n";
    
    std::vector<std::string> items = {"Pizza" , "Burger", "Fries", "Momos", "Salad"};
    std::vector<int> prices = {120, 80, 40, 60, 100};
    menu(items, prices);
    return 0;

}