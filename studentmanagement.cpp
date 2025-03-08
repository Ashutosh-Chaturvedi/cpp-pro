#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include<vector>

#include"color.h"

void printWithDelay(const std::string& text, const std::string& formats = RESET, int delay = 30) {
    std::cout << formats; 
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << RESET;
}

void progressBar() {
    std::cout << "Processing: [" << BLUE;
    
    for (int i = 0; i < 20; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "#";
        std::cout.flush(); 
    }
    std::cout << RESET << "] Done!\n";
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

void newAdmission(std::vector<student>& students) {
    printWithDelay("\n\tNew Admission\n",BOLD_BLUE);
    int rollno = getValidatedInput<int>("Enter roll number: ",true);
    std::string name;
    printWithDelay("Enter the name: ");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    int age = getValidatedInput<int>("Enter age: ", true);
    char grade = getValidatedInput<char>("Enter grade: ", true);
    student* s = new student(rollno,name,age,grade);
    students.push_back(*s);
    progressBar();
    printWithDelay("\nSTUDENT DETAIL ADDED SUCCESSFULLY\n",BOLD_GREEN);
    return;
}

void list(std::vector<student>& students) {

}

void menu(std::vector<student>& students) {
    printWithDelay( "\nWelcome to the Student Management System\n", BOLD_BLUE);
    printWithDelay("1. New Admission\n");
    printWithDelay("2. List Students\n");
    printWithDelay("0. Exit\n");
    int choice = getValidatedInput<int>("Choose from the above options: ", true, BOLD_GREEN);
    switch (choice)
    {
    case 1:
        newAdmission(students);
        break;
    case 2:
        list(students);
        break;
    case 0:
        return;
    default:
        std::cout << BOLD_RED << "Invalid option" << RESET;
        break;
    }
    menu(students);
}

int main() {
    std::vector<student> students;
    system("cls");
    menu(students);
}