#include <iostream>
using namespace std;

int LCS(string s1, string s2, string s3, int l1, int l2, int l3){
    if(l1 == 0 || l2 == 0){
        return 0;
    }

    if(s1[l1-1] == s2[l2-1] && s2[l2-1] == s3[l3-1]){
        return 1 + LCS(s1, s2, s3, l1-1, l2-1, l3-1);
    }

    return max({LCS(s1, s2, s3, l1-1, l2, l3), LCS(s1, s2, s3, l1, l2-1, l3), LCS(s1, s2, s3, l1, l2, l3-1)});
}


int main(){
    return 0;
}