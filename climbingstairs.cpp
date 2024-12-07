#include<iostream>
#include<vector>
#include<bits/stdc++.h>

long long climbStairs(long long n) {
        std::vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];        
}

int main(){
    std::cout << "This program will help to find the number of ways of climb the stairs if a person can climb either 1 or 2 stairs at a time." << std::endl;
    int n ;
    std::cout << "Enter the number of stairs: ";
    std::cin >> n;

    std::cout << "The number of ways to climb the stairs is: " << climbStairs(n) << std::endl;
}