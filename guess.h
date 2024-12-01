#include<iostream>

void guess(int x);

void check(int x , int guessed){
    if(x > guessed){
        std::cout << "TOO HIGH \n";
        guess(guessed);
    }
    if(x < guessed){
        std::cout << "TOO LOW \n";
        guess(guessed);
    }
    if(x == guessed){
        std::cout << "CORRECT" << std::endl;
    }
}