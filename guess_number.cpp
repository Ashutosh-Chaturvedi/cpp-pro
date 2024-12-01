#include<iostream>
#include<cstdlib>
#include<time.h>
#include "guess.h"

void guess(int guessed){
    std::cout << "Guess the number: ";
    int x ;
    std::cin >> x;
    check(x, guessed);
}

int main(){
    std::cout << std::endl;
    std::cout << "Generating a random number.... \n5.. \n4.. \n3.. \n2.. \n1... \n";

    srand(time (0));
    int x = rand() % 100;
    std::cout << "The number is now GENERATED and you are good to GUESS it. \n \n";
    guess(x);
}

