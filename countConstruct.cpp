#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Memoization

// int countConstruct(string target, vector<string> &words){
//     if(target == ""){
//         return 1;
//     }

//     int ans = 0;

//     for(auto word: words){
//         if(target.find(word) == 0){
//             string subString = target.substr(word.length());
//             ans += countConstruct(subString, words);
//         } 
//     }

//     return ans;
// }

// Tabulation

int countConstruct(string target, vector<string>&words){
    int len = target.length();

    vector<int> tab(len+1, 0);
    tab[0] = 1;

    for(int i = 0; i <= len; ++i){
        for(auto word: words){
            if(target.substr(i, word.length()) == word){
                tab[i+word.length()] += tab[i];
            }
        }
    }

    return tab[len];
}

int main(){
    vector<string> arr1 = {"ab", "abc", "cd", "def", "abcd"};
    vector<string> arr2 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    vector<string> arr3 = {"purp", "p", "ur", "le", "purpl"};

    cout<<countConstruct("purple", arr3)<<endl;
    return 0;
}