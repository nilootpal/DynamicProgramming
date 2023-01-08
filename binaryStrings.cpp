#include <iostream>
#include <vector>

using namespace std;

void countBinaryStrings(int n, vector<int>&ones, vector<int>&zeros){
    if(n == 1){
        ones[n] = 1;
        zeros[n] = 1;
        return;
    }

    countBinaryStrings(n-1, ones, zeros);

    ones[n] = zeros[n-1];
    zeros[n] = ones[n-1] + zeros[n-1];
}

int main(){
    vector<int> ones(4, 0);
    vector<int> zeros(4, 0);

    countBinaryStrings(3, ones, zeros);

    cout<<ones[3] + zeros[3]<<endl;
    return 0;
}

// Fibonacci sequence