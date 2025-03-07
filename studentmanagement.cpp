#include<iostream>
#include<string>
#include<chrono>
#include<thread>

#include"color.h"

void printWithDelay(const std::string& text, const std::string& formats = RESET, int delay = 30) {
    std::cout << formats; 
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << RESET;
}

template <typename T>
T getValidatedInput(const std::string& prompt, bool mustBePositive = false, const std::string& color = RESET) {
    T value;
    while (true) {
        printWithDelay(prompt, color);
        std::cin >> value;

        if (std::cin.fail() || (mustBePositive && value < 0)) { 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid " << (mustBePositive ? "positive " : "") << "number." << std::endl;
        } else {
            return value;
        }
    }
}

class student {
    public:
    int rollno;
    std::string name;
    int age;
    char grade;
    student(int rollno,std::string name,int age,char grade){
        this->rollno = rollno;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }
};

class grade {
    public:
    student* s;
    grade(student* s){
        this->s = s;
    }
};

void newAdmission() {
    
}

void list() {

}

void menu() {
    std::cout << BOLD_GREEN << "1. " << RESET << BOLD << "New Admission\n" << RESET;
    std::cout << BOLD_GREEN << "2. " << RESET << BOLD << "List Students\n" << RESET;
    std::cout << BOLD_RED << "0. " << RESET << BOLD << "Exit\n" << RESET;
    int choice = getValidatedInput<int>("Choose from the above options: ", true, BOLD_GREEN);
    switch (choice)
    {
    case 1:
        newAdmission();
        break;
    case 2:
        list();
        break;
    case 0:
        return;
    default:
        std::cout << BOLD_RED << "Invalid option" << RESET;
        break;
    }
}

int main() {
    printWithDelay( "\nWelcome to the Student Management System\n", BOLD_BLUE);
    menu();
    newAdmission();
    list();
}