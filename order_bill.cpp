#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

typedef std::vector<int> _int;
typedef std::vector<std::string> _string;

using _string = std::vector<std::string>;
using _int = std::vector<int>;
using _double = std::vector<double>;
using _bool = std::vector<bool>;
using V_string = std::vector<std::vector<std::string>>;
using V_int = std::vector<std::vector<int>>;
using V_double = std::vector<std::vector<double>>;

auto& cout = std::cout; 
auto& cin = std::cin;
auto& endline = std::cout << std::endl;

void menu(_string & menuList, _double &price, std::string name);
void order(int b, _string & menuList, _double &price, _int &orders, _int & cost, _int & quantity, std::string name);

void orderSummary(_int & orders,_string & menuList, _double & price, _int & cost, _int & quantity, std::string name){

    cout << "______________________________________________\n\n";
    cout << "CUSTOMER'S NAME: " << name << "\t"; 
    cout << "ORDER ID- " << rand() << std::endl;

    cout << "\n \tORDER SUMMARY \n";
    cout << "Code\tItem\t Quantity \tRate\t Cost\n";

    int totalQuantity = 0;
    double totalCost = 0;

    for(int i = 0; i < orders.size(); i++){
        int index = orders[i];
        totalCost = totalCost + (price[index] * quantity[i]);
        totalQuantity = totalQuantity + quantity[i];
        cout << " "<< index + 1 << "     " << menuList[index] << "\t\t" << quantity[i] << "\t$" << price[index] << "\t$" << quantity[i] * price[index] << '\n';
    }

    cout << "\nTotal\t\t\t" << totalQuantity << "\t\t$" << totalCost << '\n';
    cout << "______________________________________________\n";

    int n;
    cout << "\nIf you want to add more items press 1.";
    cin >> n;
    if(n == 1){
        order(1, menuList, price, orders, cost, quantity, name);
        orderSummary(orders, menuList, price, cost, quantity, name);
    }
    endline;

}

void order(int b, _string & menuList, _double &price, _int &orders, _int & cost, _int & quantity, std::string name)
{
    if(b == 0) return;
    int n;
    cout << "\nEnter the code for what you want to order: ";
    cin >> n;
    if(n > menuList.size()){
        cout << "Invalid code. Please enter a valid code.\n";
        order(b, menuList, price, orders, cost, quantity, name);
        return;
    }

    int quan;
    cout << "Enter quantity of " << menuList[n-1] << " you want to order: ";
    cin >> quan;
    if(n > 0 && n <= price.size()) {
        cout << "You have ordered " << quan << " " << menuList[n-1] << " for " << price[n-1] <<"$ each "<< '\n';
        orders.push_back(n-1);
        quantity.push_back(quan);
        b--;
    } else {
        cout << "Invalid Option \n Try again\n";
    }
    order(b,menuList, price, orders, cost, quantity, name);
}

void menu(_string & menuList, _double &price, std::string name) {

    endline;
    cout << "Code\t Item \t Price \n";
    for(int i = 0; i < price.size(); i++){
        cout << " " << i+1 << ".\t" << menuList[i] << " \t $" << price[i] << '\n';
    } 
    int n;
    cout << "\nEnter the number of different dishes you want to order: ";
    cin >> n;
    _int orders;
    _int cost;
    _int quantity;
    order(n , menuList, price, orders, cost, quantity, name);
    orderSummary(orders, menuList, price, cost, quantity, name);
    cout << "\n\nWant to order again?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    int choice;
    cin >> choice;
    if(choice == 1) {
        menu(menuList, price, name);
    }

}
int main(){
    cout << "\n \tWELCOME \n\n";
    _string items = {"Pizza" , "Burger", "Fries", "Momos", "Salad"};
    _double prices = {1.2, 0.8, 0.4, 0.6, 1};
    std::string first_name;
    std::string last_name;
    cout << "Enter the first name ";
    cin >> first_name;
    cout << "Enter the last name ";
    cin >> last_name;

    std::string name = first_name + " " + last_name;
    
    menu(items, prices, name);
    return 0;
}