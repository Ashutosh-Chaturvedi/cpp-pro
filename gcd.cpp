#include<iostream>

int gcd( int a , int b ) {
    if( a==b ) return a;
    int ans ;
    if ( a > b ){
         ans = gcd( a - b , b );
    } else {
         ans = gcd( a , b - a);
    }
    return ans;
}

int main(){
    
    std::cout << "Enter the numbers to find gcd: ";
    int a ;
    int b ;
    std::cin >> a >> b ;
    std::cout << "The gcd is " << gcd(a,b) << std::endl;

}