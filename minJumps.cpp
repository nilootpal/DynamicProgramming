#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minJumps(vector<int>&nums){
    int len = nums.size();
    vector<int> tab(len, INT_MAX);

    if(nums[0] == 0){
        return -1;
    }

    tab[0] = 0;

    for(int i = 1; i < len; ++i){
        for(int j = 0; j < i; ++j){
            if(i <= (j+nums[j])){
                tab[i] = min(tab[i], 1+tab[j]);
            }
        }
    }

    return tab[len-1];
}

int main(){
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<minJumps(arr)<<endl;
    return 0;
}