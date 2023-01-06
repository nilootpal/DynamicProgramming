#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Memoization

// vector<vector<string>> allConstruct(string target, vector<string>&words){
//     if(target == ""){
//         return {{}};
//     }

//     vector<vector<string>> res = {};

//     for(auto word: words){
//         if(target.find(word) == 0) {
//             string subString = target.substr(word.length());
//             vector<vector<string>> suffixWays = allConstruct(subString, words);

//             for(auto it : suffixWays){
//                 vector<string> temp = it;
//                 temp.insert(temp.begin(), word);
//                 res.push_back(temp);
//             }
//         }
//     }

//     return res;
// }


// Tabulation

vector<vector<string>> allConstruct(string target, vector<string>&words){
    int len = target.size();

    vector<vector<vector<string>>> tab(len+1);

    tab[0] = {{}};

    for(int i = 0; i <= len; ++i){
        for(auto word: words){
            if(target.substr(i, word.length()) == word){
                vector<vector<string>> temp = tab[i];
                for(auto it : temp){
                    it.push_back(word);
                    tab[i + word.length()].push_back(it);
                }
            }
        }
    }

    return tab[len];
}

int main(){
    vector<string> arr1 = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};

    vector<vector<string>> ans = allConstruct("abcdef", arr1);

    for(auto it: ans){
        for(auto x: it){
            cout<<x<<"   ";
        }
        cout<<endl;
    }cout<<endl;

    return 0;
}