#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
    private:
    bool knows(vector<vector<int>> &M, int a , int b , int n){
        if(M[a][b] == 1){
            return true;
        } else {
            return false;
        }
    }
    public:
    int celebrity(vector<vector<int> >& M, int n)
    {
        stack<int> s;

        //Step 1: Push all elements in stack
        for( int i = 0; i < n ; i++ ){
            s.push(i);
        }

        //Step 2:
        while(s.size() > 1){
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
    
        int candidate = s.top();
        //Step 3: Single element in sstack is potential Celebrity
        bool rowCheck = false;
        int zeroCount = 0;

        for(int i = 0; i < n ; i++ ){
            if(M[candidate][i] == 0){
                zeroCount++;
            }
        }

        //all Zeroes 
        if(zeroCount == n){
            rowCheck = true;
        }

        //column Check
        bool colCheck = false;
        int oneCount = 0;
        for(int i = 0; i < n ; i++ ){
            if(M[i][candidate] == 1){
                oneCount++;
            }
        }

        if(oneCount == n - 1){
            colCheck = true;
        }

        if(rowCheck == true && colCheck == true){
            return candidate;
        } else {
            return -1;
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> M = {{0, 1, 0},{0, 0, 0},{0, 1, 0}};
    int n = 3;
    cout << solution.celebrity(M, n);
}