#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Memoization

// map<pair<int, int>, int> memo;

// int LCS(string s1, string s2, int l1, int l2){
//     if(memo[{l1, l2}]){
//         return memo[{l1, l2}];
//     }

//     if(l1 == 0 || l2 == 0){
//         return 0;
//     }

//     if(s1[l1-1] == s2[l2-1]){
//         return memo[{l1, l2}] = 1 + LCS(s1, s2, l1-1, l2-1);
//     }

//     return memo[{l1, l2}] = max(LCS(s1, s2, l1-1, l2), LCS(s1, s2, l1, l2-1));
// }

// Tabulation

int LCS(string s1, string s2, int l1, int l2){
    vector<vector<int> > tab(l1+1, vector<int>(l2+1, -1));

    for(int i = 0; i <= l1; ++i){
        for(int j = 0; j <= l2; ++j){
            if(i == 0 || j == 0){
                tab[i][j] = 0;
                continue;
            }

            if(s1[i-1] == s2[j-1]){
                tab[i][j] = 1 + tab[i-1][j-1];
            }
            else{
                tab[i][j] = max(tab[i][j-1], tab[i-1][j]);
            }
        }
    }

    return tab[l1][l2];
}

int main(){
    string s1 = "RISHABH";
    string s2 = "SHUBHI";

    cout<<LCS(s1, s2, 7, 6)<<endl;
    return 0;
}