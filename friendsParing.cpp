#include <iostream>

using namespace std;

int friendsParing(int n){
    if(n == 0){
        return 1;
    }

    if(n < 0){
        return 0;
    }

    return friendsParing(n-2) + (n-1)*friendsParing(n-1);
}

int main(){
    cout<<friendsParing(3)<<endl;
    return 0;
}