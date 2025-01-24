#include<iostream>
#include<vector>

using matrix = std::vector<std::vector<char>>;
auto& cout = std::cout;
auto& cin = std::cin;
auto& endline = std::cout << std::endl;

void viewgrid(matrix& grid);

void input(matrix& grid, char option){

    int index;
    cout << "Choose the index for " << option << ": ";
    cin >> index;

    if(index >= 0 && index < 10){
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
    for(int i = 1; i <= 9; i++){
        if(i % 2 != 0)
            input(grid, 'X');
        else 
            input(grid, 'O');
        viewgrid(grid);
    }
}