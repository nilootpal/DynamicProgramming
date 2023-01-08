#include <iostream>
#include <vector>

using namespace std;

int kOrderLCS(vector<int>&nums1, vector<int>&nums2, int i, int j, int k){
    int n = nums1.size();
    int m = nums2.size();


    if(i == n || j == m){
        return 0;
    }

    int c1(0), c2(0), c3(0);

    if(nums1[i] == nums2[j]){
        c1 = 1 + kOrderLCS(nums1, nums2, i+1, j+1, k);
    }

    if(k > 0){
        c2 = 1 + kOrderLCS(nums1, nums2, i+1, j+1, k-1);
    }

    c3 = max(kOrderLCS(nums1, nums2, i+1, j, k), kOrderLCS(nums1, nums2, i, j+1, k));

    return max({c1, c2, c3});
}

int main(){
    return 0;
}