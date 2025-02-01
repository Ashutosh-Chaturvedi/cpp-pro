/*

    BASIC INSTRUCTION
    1. Player 1 is 'X' and Player 2 is 'O'.
    2. Player 1 goes first, then Player 2.
    3. To make a move, type the number of the square where you want to place.
    4. If you want to quit, type 'q' or 'quit'.
    5. If you want to reset the game, type 'r' or 'reset'.
    6. If you want to see the game history, type 'h' or 'history'.
    7. If you want to see the game rules, type 'i' or 'info.
    8. Indexes are as follows:
        1 | 2 | 3
        ---------
        4 | 5 | 6
        ---------
        7 | 8 | 9
    9. The game will automatically switch between players after each move.

*/


#include<iostream>
#include<vector>

using matrix = std::vector<std::vector<char>>;
using string = std::string;
auto& cout = std::cout;
auto& cin = std::cin;
auto& endline = std::cout << std::endl;

void viewgrid(matrix& grid);

bool checkWinner(matrix& grid, char option){

    // cout << "Passed \n";
    for(int i = 0; i < 3; i++){
        if(grid[i][0] == option && grid[i][1] == option && grid[i][2] == option){
            return true;
        }
    }
    for(int i = 0; i < 3; i++){
        if(grid[0][i] == option && grid[1][i] == option && grid[2][i] == option){
            return true;
        }
    }
    if(grid[0][0] == option && grid[1][1] == option && grid[2][2] == option){
        return true;
    }
    if(grid[0][2] == option && grid[1][1] == option && grid[2][0] == option){
        return true;
    }

    return false;
}

bool isAlreadyPresent(matrix& grid, int index){
    if(index <= 3){
            if(grid[0][index - 1] == '.') return false;
    }
    else if(index <= 6){
            if(grid[1][index - 4] == '.') return false;
    } 
    else {
            if(grid[2][index - 7] == '.') return false;
    }
    return true;
}

int input(matrix& grid, char option){

    int index;
    cout << "\nChoose the index for " << option << ": ";
    cin >> index;
    cout << "\n";
    bool isPresent = isAlreadyPresent(grid, index);
    
    if(index > 0 && index < 10 && (isPresent == false)) {
        if(index <= 3){
            grid[0][index - 1] = option;
        }
        else if(index <= 6){
            grid[1][index - 4] = option;
        } 
        else {
            grid[2][index - 7] = option;
        }
    } 
    
    else if(index == -1 || index == 0){
        return index;
    }

    else {
        if (cin.fail()) {
            cin.clear();  
            cin.ignore(1000, '\n');  
        }
        cout << "Invalid index\n";
        input(grid, option);
    }
    return 1;
}

void viewgrid(matrix& grid) {
    for(int i = 0 ; i < grid.size(); i++){
        cout << "\t";
        for(int j = 0 ;j < grid.size(); j++){
            cout << grid[i][j] << "  ";
        } 
        cout << "\n";
    }
}

void startMenu(int opt){
    int choice;
    int index = {};
    if(opt == 1){
        cout << "Welcome to Tic Tac Toe\n";
        cout << "1. New Game\n";
        cout << "2. Info\n";
        cout << "3. History\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;       
    }
    if(choice == 1 || opt == 0) {
        cout << "\nBasic Commands:\nTo exit: -1.\nTo Restart: 0.\n\nIndexes are as follows:\n\n\t1 | 2 | 3\n\t---------\n\t4 | 5 | 6\n\t---------\n\t7 | 8 | 9\n\n";
        matrix grid = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
        char option;
        for(int i = 1; i <= 9; i++){    
            if(i % 2 != 0)
                option = 'X';
            else {
                option = 'O';
            }
            index = input(grid, option);
            if(index == -1) break;
            if(index == 0){
                break;
            }
            viewgrid(grid);
            if(i > 4){
                if(checkWinner(grid,option)){
                    cout << "\nCONGRATULATIONS!!!\nPlayer " << option << " wins!!!\n\n";
                    break;
                }
            }
        }
    }
    else if(choice == 2) {
        cout << "This is a simple implementation of Tic Tac Toe\n";
        cout << "BASIC INSTRUCTION\n1. Player 1 is 'X' and Player 2 is 'O'.\n2. Player 1 goes first, then Player 2.\n3. To make a move, type the number of the square where you want to place.\n\n4. Indexes are as follows:\n1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9\n5. The game will automatically switch between players after each move.";
        cout << "Press any key to continue...\n";
        cin.get();
    }
    else if(choice == 3) {

    }
    else if(choice == 4) {
        cout << "Exiting...\n";
        return;
    }
    if(index == 0) {
        startMenu(0);
    }
    else 
        startMenu(1);

}

int main(){
    startMenu(1);
    return 0;
}