#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<pair<int,int>, int> memo;

int knapSack(vector<int>&weights, vector<int>&values, int weight, int items){
    if(memo[{weight, items}]){
        return memo[{weight, items}];
    }

    if(weight < 0){
        return 0;
    }

    if(items <= 0){
        return 0;
    }

    if(weights[items-1] > weight){
        return memo[{weight, items}] = knapSack(weights, values, weight, items-1);
    }

    return memo[{weight, items}] = max(knapSack(weights, values, weight, items-1),knapSack(weights, values, weight-weights[items-1], items-1)+values[items-1]);
}

int main(){
    vector<int> weights = {15, 30, 45};
    vector<int> values = {60, 100, 150};

    cout<<knapSack(weights, values, 60, 3)<<endl;
    return 0;
}