#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Tabulation

// int longestIncreasingSubsequence(vector<int>&nums){
//     int n = nums.size();

//     vector<int> tab(n, 1);

//     for(int i = 0; i < n; ++i){
//         for(int j = 0; j < i; ++j){
//             if(nums[i] > nums[j]){
//                 tab[i] = max(tab[i], tab[j]+1);
//             }
//         }
//     }

//     return tab[n-1];
// }

// Memoization

map<int, int> memo;

int longestIncreasingSubsequence(vector<int>&nums, int idx){
    if(memo[idx]){
        return memo[idx];
    }

    memo[idx] = 1;

    for(int i = idx-1; i >= 0; --i){
        if(nums[i] < nums[idx]){
            int temp = longestIncreasingSubsequence(nums, i);
            memo[idx] = max(memo[idx], 1 + temp);
        }
    }

    return memo[idx];
}

int main(){
    vector<int> arr = {10, 22, 9, 33, 21, 50, 52, 60, 80}; 
    
    cout<<longestIncreasingSubsequence(arr, 8)<<endl;

    return 0;
}