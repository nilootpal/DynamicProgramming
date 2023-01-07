#include <iostream>
#include <vector>

using namespace std;

int optimalGame(vector<int>&coins, int i, int j){
    if(i == j){
        return coins[i];
    }

    int choice1 = coins[i] + min(optimalGame(coins, i+2, j), optimalGame(coins, i+1, j-1));
    int choice2 = coins[j] + min(optimalGame(coins, i, j-2), optimalGame(coins, i+1, j-1));

    return max(choice1, choice2);
}

int main(){
    return 0;
}