#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Memoization

// map<int, vector<int>> memo;

// vector<int> howSum(int target, vector<int>&arr){
//     if(!memo[target].empty()){
//         return memo[target];
//     }

//     if(target == 0){
//         return {0};
//     }
//     if(target < 0){
//         return {-1};
//     }

//     for(auto x : arr){
//         vector<int> temp = howSum(target-x, arr);

//         if(temp[0] != -1){
//             temp.push_back(x);
//             memo[target] = temp;
//             return temp;
//         }
//     }

//     memo[target] = {-1};
//     return memo[target];
// }

// Tabulation

vector<int> howSum(int target, vector<int>&arr){
    vector<vector<int>> tab(target+1);

    tab[0] = {};

    for(int i = 0; i <= target; ++i){
        if(i == 0 || !tab[i].empty()){
            for(auto x: arr){
                if(i+x <= target){
                    tab[i+x] = tab[i];
                    tab[i+x].push_back(x);
                }
            }
        }
    }

    return tab[target];
}

int main(){
    vector<int> arr = {5, 3, 4, 7};
    vector<int> ans = howSum(7, arr);

    for(auto x : ans){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}