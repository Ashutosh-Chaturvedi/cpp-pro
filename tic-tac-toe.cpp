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

void input(matrix& grid, char option){

    int index;
    cout << "Choose the index for " << option << ": ";
    cin >> index;
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
    
    else {
        cout << "Invalid index\n";
        input(grid, option);
    }
}

void viewgrid(matrix& grid) {
    for(int i = 0 ; i < grid.size(); i++){
        for(int j = 0 ;j < grid.size(); j++){
            cout << grid[i][j] << "  ";
        } 
        cout << "\n";
    }
}

int main(){
    matrix grid = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    viewgrid(grid);
    char option;
    for(int i = 1; i <= 9; i++){    
        if(i % 2 != 0)
            option = 'X';
        else {
            option = 'O';
        }
        input(grid, option);
        viewgrid(grid);
        if(i > 4){
            if(checkWinner(grid,option)){
                cout << "Player " << option << " wins\n";
                break;
            }
        }
    }
    return 0;
}