#include <iostream>
#include <vector>
#include <map>

using namespace std;

int knapSack(vector<int>&weights, vector<int>&values, int weight, int items){
    if(weight < 0){
        return 0;
    }

    if(items <= 0){
        return 0;
    }

    if(weights[items-1] > weight){
        return knapSack(weights, values, weight, items-1);
    }

    int itemLeft = knapSack(weights, values, weight, items-1);
    int itemIncludedAndNotLeft = knapSack(weights, values, weight-weights[items-1], items) + values[items-1];

    return max(itemLeft, itemIncludedAndNotLeft);
}

int main(){
    vector<int> weights = {3, 2, 4, 5, 1};
    vector<int> values = {4, 3, 5, 6, 1};

    cout<<knapSack(weights, values, 11, 5)<<endl;

    // Tabulation

    // vector<int> dp(12, 0);

    // for(int i = 0; i < 12; ++i){
    //     for(int j = 0; j < 5; ++j){
    //         if(weights[i] <= j){
    //             dp[j] = max(dp[j], values[i] + dp[j-weights[i]]);
    //         }
    //     }
    // }
    
    return 0;
}