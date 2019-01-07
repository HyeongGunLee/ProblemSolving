#include <iostream>
#include <string>
#include <map>
using namespace std;

const map<char, int> ROMAN = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
};

int romanToInt(string s) {
    int sum = 0;
    int roman_len = s.length();
    for (int i = 0; i < roman_len; i++) {
        if (i < roman_len-1 && ROMAN.at(s[i]) < ROMAN.at(s[i+1])) { // if decrease
            int diff = ROMAN.at(s[i+1]) - ROMAN.at(s[i]);
            sum += diff;
            i++;
        } else { // if same or increase
            sum += ROMAN.at(s[i]);
        }
    }
    return sum;
}

int main(void) {
    string test1 = "III";
    string test2 = "IV";
    string test3 = "IX";
    string test4 = "LVIII";
    string test5 = "MCMXCIV";
    cout << romanToInt(test5) << endl;
}

