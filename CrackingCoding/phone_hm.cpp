#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


vector<string> letterCombinationHelp(string digits, int index, string temp, vector<string>& result, unordered_map<char, string>& hm) {
    int size = digits.length();
    if (index == size) {
        result.push_back(temp);
        return result;
    }

    string s = hm[digits[index]];
    int len = s.length();
    for (int i = 0; i < len; i++) {
        temp.push_back(s[i]);
        letterCombinationHelp(digits, index+1, temp, result, hm);
        temp.pop_back();
    }
    return result;
}


vector<string> letterCombinations(string digits) {
    unordered_map<char, string> hm = {{'0', ""}, {'1', ""}, {'2', "abc"},
                                      {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"},
                                      {'9', "wxyz"}};
    vector<string> result;

    return letterCombinationHelp(digits, 0, "", result, hm);
}


int main(void) {
    vector<string> result = letterCombinations("23");
    vector<string>::iterator it;
    for (it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }

}