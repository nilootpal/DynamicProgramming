#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

// Memoization

// map<pair<int, int>, int> memo;

// int matrixChainMultiplication(vector<int>&mat, int i, int j){
//     if(memo[{i, j}]){
//         return memo[{i, j}];
//     }

//     if(i == j){
//         return 0;
//     }

//     int ans = INT_MAX;

//     for(int k = i; k < j; ++k){
//         ans = min(ans, matrixChainMultiplication(mat, i, k) + matrixChainMultiplication(mat, k+1, j) + mat[i-1]*mat[k]*mat[j]);
//     }

//     return memo[{i, j}] = ans;
// }

// Tabulation

int MatrixChainMultiplication(vector<int>&mat, int n){
    int dp[n-1][n-1];

    for(int gap = 0; gap < n-1; gap++){
        for(int i = 0, j = gap; j < n-1; i++, j++){
            if(gap==0)
                dp[i][j]=0;
            else if(gap==1){
                dp[i][j]=mat[i]*mat[j]*mat[j+1];
            }
            else{
                int minCost=INT_MAX;

                for(int k=i;k<j;k++){
                    int leftCost=dp[i][k];
                    int rightCost=dp[k+1][j];
                    int thisCost=mat[i]*mat[k+1]*mat[j+1];
                    
                    minCost=min(minCost,leftCost + rightCost+thisCost);
                }
                dp[i][j]=minCost;
            }
        }
    }
    return dp[0][n-2];
}

int matrixChainMultiplication(vector<int>&mat, int n){
    vector<vector<int>> tab(n+1, vector<int>(n+1));

    for(int k = 1; k < n; ++k){
        tab[k][k] = 0;
    }

    for(int len = 2; len < n; ++len){
        for(int i = 1; i <= n - len + 1; ++i){
            int j = i+len-1;
            tab[i][j] = INT_MAX;
            for(int k = i; k < j; ++k){
                tab[i][j] = min(tab[i][j], tab[i][k] + tab[k+1][j] + mat[i-1]*mat[k]*mat[j]);
            }
        }
    }

    return tab[1][n-1];
}


int main(){
    vector<int> arr = {10, 20, 30, 20, 30};
    cout<<matrixChainMultiplication(arr, 5)<<endl;

    return 0;
}