#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void cbroot() {
  cout << endl;
  cout << endl;
  cout << "Cube root " << endl;
  cout << endl;
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << "Cube root of " << n << " is " << cbrt(n) << endl;
  int ch;
  cout << "Want to perform it again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    cbroot();
  } else {
    cout << endl;
    return;
  }
}
void cb() {
  cout << endl;
  cout << endl;
  cout << "Cube (x^3)" << endl;
  cout << endl;
  int n;
  cout << "Enter the number : ";
  cin >> n;
  cout << n << " x " << n << " x " << n << " = " << n * n << endl;
  int ch;
  cout << "Want to perform it again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    cb();
  } else {
    cout << endl;
    return;
  }
}
void sqroot() {
  cout << endl;
  cout << endl;
  cout << "square root " << endl;
  cout << endl;
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << "Square root of " << n << " is " << sqrt(n) << endl;
  int ch;
  cout << "Want to perform it again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    sqroot();
  } else {
    cout << endl;
    return;
  }
}
void sq() {
  cout << endl;
  cout << endl;
  cout << "square (x^2)" << endl;
  cout << endl;
  int n;
  cout << "Enter the number : ";
  cin >> n;
  cout << n << " x " << n << " = " << n * n << endl;
  int ch;
  cout << "Want to perform it again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    sq();
  } else {
    cout << endl;
    return;
  }
}
void power() {
  cout << endl;
  cout << endl;
  cout << "Power (x^y)" << endl;
  cout << endl;
  int n;
  cout << "Enter base: ";
  cin >> n;
  int m;
  cout << "Enter the power: ";
  cin >> m;
  cout << n << " to the power of " << m << " = " << pow(n, m) << endl;
  int ch;
  cout << "Want to perform it again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    power();
  } else {
    cout << endl;
    return;
  }
}
long long factorial(long long n) {
  if (n == 1) {
    cout << 1 << " = ";
    return 1;
  } else {
    cout << n << " x ";
    return n * factorial(n - 1);
  }
}
void fac() {
  cout << endl;
  cout << endl;
  cout << "Factorial (!)" << endl;
  cout << endl;
  long long n;
  cout << "Enter the number: ";
  cin >> n;
  cout << n << "! = " << factorial(n) << endl;
  int ch;
  cout << "Want to perform it again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    fac();
  } else {
    cout << endl;
    return;
  }
}
void div() {
  cout << endl;
  cout << endl;
  cout << "Division (/)" << endl;
  cout << endl;
  float n, m;
  cout << "Enter first Number: ";
  cin >> n;
  cout << "Enter second Number: ";
  cin >> m;
  cout << n << " / " << m << " = " << n / m << endl;
  int ch;
  cout << "Want to perform it again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    div();
  } else {
    cout << endl;
    return;
  }
}
void mul() {
  cout << endl;
  cout << endl;
  cout << "Multiplication(x)" << endl;
  cout << endl;
  int n;
  cout << "How many numbers you want to multiply?";
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cout << "Enter a number:";
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i == (n - 1))
      cout << " = ";
    else
      cout << " x ";
  }
  int m = 1;
  for (int i = 0; i < n; i++) {
    m = m * a[i];
  }
  cout << m << endl;
  int ch;
  cout << "Want to do multiplication again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    mul();
  } else {
    cout << endl;
    return;
  }
}
void sub() {
  cout << endl;
  cout << endl;
  cout << "Substraction (-)" << endl;
  cout << endl;
  int n;
  cout << "How many numbers you want to sub?";
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cout << "Enter a number:";
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i == (n - 1))
      cout << " = ";
    else
      cout << " - ";
  }
  // int dif = 0;
  // for(int i=n-1; i>=0; i--){
  //   if(i!=0) dif = dif - a[i];
  //   else dif = a[i] + dif;
  // }
  int d = a[0];
  for (int i = 0; i < n; i++) {
    d = d - a[i];
  }
  cout << d << endl;
  int ch;
  cout << "Want to do subtraction again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    sub();
  } else {
    cout << endl;
    return;
  }
}
void add() {
  cout << endl;
  cout << endl;
  cout << "Addition (+)" << endl;
  cout << endl;
  int n;
  cout << "How many numbers you want to add?";
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cout << "Enter a number:";
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i == (n - 1))
      cout << " = ";
    else
      cout << " + ";
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum + a[i];
  }
  cout << sum << endl;
  cout << endl;
  int ch;
  cout << "Want to do addition again?(1-yes/0-no) :";
  cin >> ch;
  if (ch == 1) {
    cout << endl;
    add();
  } else {
    cout << endl;
    return;
  }
}

void cal() {
  cout << endl;
  int n;
  cout << "Choose the operation you want to perform: " << endl;
  cout << "1- Addition " << endl;
  cout << "2- Substraction" << endl;
  cout << "3- Multiplication" << endl;
  cout << "4- Division" << endl;
  cout << "5- Factorial" << endl;
  cout << "6- x to the power y" << endl;
  cout << "7- Square" << endl;
  cout << "8- Square root" << endl;
  cout << "9- Cube " << endl;
  cout << "10- Cube root" << endl;
  cout << "11- Back to menu" << endl;
  cout << "0- To exit" << endl;
  cout << "Choose from 1 to 10: ";
  cin >> n;
  if (n == 1)
    add();
  else if (n == 2)
    sub();
  else if (n == 3)
    mul();
  else if (n == 4)
    div();
  else if (n == 5)
    fac();
  else if (n == 6)
    power();
  else if (n == 7)
    sq();
  else if (n == 8)
    sqroot();
  else if (n == 9)
    cb();
  else if (n == 10)
    cbroot();
  else if (n == 11)
    return;
  else if (n == 0) {
    cout << endl;
    cout << "The program is terminated.";
    exit(0);
  } else {
    cout << "You Choosed an invalid operator." << endl;
    cout << "Try again." << endl;
    cal();
  }
  int ret;
  cout << "For returning back to CALCULATOR page choose 1 else will be "
          "returned to MAIN MENU: ";
  cin >> ret;
  if (ret == 1)
    cal();
  else
    return;
}

int main(){
    cout << endl <<  "Welcome to Calculator" << endl;
    cal();
}