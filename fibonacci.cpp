#include <iostream>
#include <vector>
using namespace std;

// Memoization

// long long memo[1000] = {0};

// long long fibo(int n){
//     if(n <= 2){
//         return 1;
//     }

//     if(memo[n]){
//         return memo[n];
//     }
    
//     memo[n] = fibo(n-1) + fibo(n-2);
//     return memo[n];
// }

// Tabulation

long long fibo(int n){
    vector<long long> tab(n+1, 0);
    tab[1] = 1;
    
    for(int i = 0; i <= n; ++i){
        tab[i+1] += tab[i];
        tab[i+2] += tab[i];
    }

    return tab[n];
}

int main(){
    cout<<fibo(50)<<endl;

    return 0;
}