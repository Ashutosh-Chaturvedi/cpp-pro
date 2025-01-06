#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

//using typedef to increase readability 
typedef std::vector<int> _int;
typedef std::vector<std::string> _string;

//Using 'Using aliasis" to do the same thing as done above.
using _string = std::vector<std::string>;
using _int = std::vector<int>;
using _double = std::vector<double>;
using _bool = std::vector<bool>;
using V_string = std::vector<std::vector<std::string>>;
using V_int = std::vector<std::vector<int>>;
using V_double = std::vector<std::vector<double>>;

//Since cout and cin are not data types, so we can't use the above methods.
//Using reference
auto& cout = std::cout; 
auto& cin = std::cin;
auto& endline = std::cout << std::endl;

void orderSummary(_int & orders,_string & menuList, _int & price, _int & cost, _int & quantity){

    cout << "\n\n \tORDER SUMMARY \n";
    cout << "Code\tItem\t Quantity \tRate\t Cost\n";

    int totalQuantity = 0;
    int totalCost = 0;

    for(int i = 0; i < orders.size(); i++){
        int index = orders[i];
        totalCost = totalCost + (price[index] * quantity[i]);
        totalQuantity = totalQuantity + quantity[i];
        cout << " "<< index + 1 << "     " << menuList[index] << "\t\t" << quantity[i] << "\t$" << price[index] << "\t$" << quantity[i] * price[index] << '\n';
    }

    cout << "\nTotal\t\t\t" << totalQuantity << "\t\t$" << totalCost << '\n';
    endline;

}

void order(int b, _string & menuList, _int &price, _int &orders, _int & cost, _int & quantity)
{
    if(b == 0) return;
    int n;
    cout << "\nEnter the code for what you want to order: ";
    cin >> n;
    if(n > menuList.size()){
        cout << "Invalid code. Please enter a valid code.\n";
        order(b, menuList, price, orders, cost, quantity);
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
    order(b,menuList, price, orders, cost, quantity);
}

void menu(_string & menuList, _int &price) {

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
    order(n , menuList, price, orders, cost, quantity);
    orderSummary(orders, menuList, price, cost, quantity);

}
int main(){
    cout << "\n \tWELCOME \n\n";
    _string items = {"Pizza" , "Burger", "Fries", "Momos", "Salad"};
    _int prices = {120, 80, 40, 60, 100};
    menu(items, prices);
    return 0;
}