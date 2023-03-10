#include <iostream>

using namespace std;

int numOfSubseq(string s){
    int n = s.length();
    int e = 1, a = 0, ab = 0, abc = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] == 'a'){
            a += e;
        }
        else if(s[i] == 'b'){
            ab += a;
        }
        else if(s[i] == 'c'){
            abc += ab;
        }
        else if(s[i] == '?'){
            abc = 3 * abc + ab;
            ab = 3 * ab + a;
            a = 3 * a + e;
        }
    }

    return abc;
}

int main(){
    return 0;
}