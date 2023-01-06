#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Memoization

// int coinChange(int target, vector<int>&coins, int size, vector<vector<int>>&memo){
//     if(target == 0){
//         return 1;
//     }

//     if(target < 0){
//         return 0;
//     }

//     if(size <= 0){
//         return 0;
//     }

//     if(memo[target][size] != -1){
//         return memo[target][size];
//     }

//     memo[target][size] = coinChange(target-coins[size-1], coins, size, memo) + coinChange(target, coins, size-1, memo);

//     return memo[target][size];
// }

// Tabulation

int coinChange(int target, vector<int>&coins, int size){
    vector<int> tab(target+1);

    tab[0] = 1;

    for(auto x : coins){
        for(int i = x; i <= target; ++i){
            tab[i] += tab[i-x];
        }
    }

    return tab[target];
}

int main(){
    vector<int> coins = {1, 2, 3};

    // vector<vector<int>> memo(7, vector<int>(4, -1)); Memoization

    cout<<coinChange(6, coins, 3)<<endl;

    return 0;
}