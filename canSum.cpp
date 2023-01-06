#include <iostream>
#include <vector>
#include <map>
using namespace std;


// Memoization

// map<int, int> memo;

// bool canSum(int target, vector<int>&arr){
//     if(memo[target] == 1){
//         return true;
//     }
//     else if(memo[target] == -1){
//         return false;
//     }

//     if(target == 0){
//         return true;
//     }
//     if(target < 0){
//         return false;
//     }

//     for(auto x : arr){
//         if(canSum(target-x, arr)){
//             memo[target] = 1;
//             return true;
//         }
//     }

//     memo[target] = -1;
//     return false;
// }

// Tabulation

bool canSum(int target, vector<int>&arr){
    vector<bool> ans(target+1, false);

    ans[0] = true;

    for(int i = 0; i <= target; ++i){
        if(ans[i]){
            for(auto x : arr){
                ans[i+x] = true;
            }
        }
    }

    return ans[target];
}

int main(){
    vector<int> arr = {5, 3, 4};
    cout<<canSum(7, arr)<<endl;
    return 0;
}