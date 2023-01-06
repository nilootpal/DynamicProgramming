#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Memoization

// map<pair<int,int>, long long> memo;

// long long gridTraveller(int x, int y){
//     if(x == 0 || y == 0){
//         return 0;
//     }

//     if(x == 1 && y == 1){
//         return 1;
//     }

//     if(memo[{x, y}]){
//         return memo[{x,y}];
//     }

//     memo[{x,y}] = gridTraveller(x-1, y) + gridTraveller(x, y-1); 

//     return memo[{x,y}];
// }

// Tabulation

long long gridTraveller(int x, int y){
    vector<vector<long long>> tab(x+1, vector<long long>(y+1, 0));

    tab[1][1] = 1;

    for(int i = 1; i <= x; ++i){
        for(int j = 1; j <= y; ++j){
            if(i+1 <= x){
                tab[i+1][j] += tab[i][j];
            }
            if(j+1 <= y){
                tab[i][j+1] += tab[i][j];
            }
        }
    }

    return tab[x][y];
}

int main(){
    cout<<gridTraveller(18, 18)<<endl;
    return 0;
}