#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Memoization

// map<int, vector<int>> memo;

// vector<int> bestSum(int target, vector<int>&arr){
//     if(!memo[target].empty()){
//         return memo[target];
//     }

//     if(target == 0){
//         return {0};
//     }

//     if(target < 0){
//         return {-1};
//     }

//     vector<int> ans = {-1};

//     for(auto x: arr){
//         vector<int> temp = bestSum(target-x, arr);
//         if(temp[0] != -1){
//             temp.push_back(x);
//             if(ans[0] == -1 || ans.size() > temp.size()){
//                 ans = temp;
//             }
//         }
//     }

//     memo[target] = ans;
//     return ans;
// }

// Tabulation

vector<int> bestSum(int target, vector<int>&arr){
    vector<vector<int>> tab(target+1, vector<int>(0));

    tab[0] = {};

    for(int i = 0; i <= target; ++i){
        if(i == 0 || !tab[i].empty()){
            for(auto x: arr){
                if(i+x <= target){
                    if(tab[i+x].empty()){
                        tab[i+x] = tab[i];
                        tab[i+x].push_back(x);
                    }
                    else{
                        vector<int> temp = tab[i];
                        temp.push_back(x);
                        if(tab[i+x].size() > temp.size()){
                            tab[i+x] = temp;
                        }
                    }
                }
            }
        }
    }

    return tab[target];
}

int main(){
    vector<int> arr = {1, 2, 5, 25};
    vector<int> ans = bestSum(100, arr);

    for(auto x : ans){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}