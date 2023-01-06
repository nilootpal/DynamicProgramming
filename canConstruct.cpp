#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


// Memoization 

// map<string, int> memo;

// bool canConstruct(string target, vector<string>&words){
//     if(memo[target] == 1){
//         return true;
//     }
//     else if(memo[target] == -1){
//         return false;
//     }

//     if(target.length() == 0){
//         return true;
//     }

//     for(auto word: words){
//         if(target.find(word) == 0){
//             string subString = target.substr(word.length());
//             if(canConstruct(subString, words)){
//                 memo[target] = 1;
//                 return true;
//             }
//         }
//     }

//     memo[target] = -1;
//     return false;
// }

// Tabulation

bool canConstruct(string target, vector<string>&words){
    int len = target.size()+1;
    vector<bool> tab(len, false);

    tab[0] = true;

    for(int i = 0; i < len; ++i){
        if(tab[i]){
            for(auto word: words){
                if(target.substr(i, word.length()) == word){
                    tab[i + word.length()] = true;
                }
            }
        }
    }

    return tab[len-1];
}

int main(){
    vector<string> arr1 = {"ab", "abc", "cd", "def", "abcd"};
    vector<string> arr2 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    vector<string> arr3 = {"e", "ee", "eee", "eeee", "eeeee"};

    cout<<canConstruct("skateboard", arr2)<<endl;
    return 0;
}