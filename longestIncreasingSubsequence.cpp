#include <iostream>
#include <vector>

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

int longestIncreasingSubsequence(vector<int>&nums){
    return 0;
}

int main(){
    vector<int> arr = {10, 22, 9, 33, 21, 50, 52, 60, 80}; 
    
    cout<<longestIncreasingSubsequence(arr)<<endl;

    return 0;
}