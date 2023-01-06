#include <iostream>
#include <climits>
#include <map>
#include <vector>

using namespace std;

// Memoization

// map<int, int> memo;

// int minNoOfSquares(int n){
//     if(memo[n]){
//         return memo[n];
//     }

//     if(n == 0 || n == 1 || n == 2 || n == 3){
//         return n;
//     }

//     int ans = INT_MAX;

//     for(int i = 1; i*i <= n; ++i){
//         ans = min(ans, minNoOfSquares(n-i*i)+1);
//     }

//     memo[n] = ans;
//     return memo[n];
// }

// Tabulation

int minNoOfSquares(int n){
    vector<int> tab(n+1, INT_MAX);
    tab[0] = 0;
    tab[1] = 1;
    tab[2] = 2;
    tab[3] = 3;

    for(int i = 1; i*i <= n; ++i){
        for(int j = 0; i*i+j <= n; ++j){
            tab[i*i+j] = min(tab[i*i+j], tab[j]+1);
        }
    }

    return tab[n];
}

int main(){

    cout<<minNoOfSquares(1024)<<endl;
    return 0;
}