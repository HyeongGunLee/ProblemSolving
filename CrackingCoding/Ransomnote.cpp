#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, int> getStringFrequency(vector<string> str) {
    unordered_map<string, int> frequencies;
    for (int i = 0; i < str.size(); i++) {
        if(frequencies.find(str[i]) == frequencies.end()) {
            frequencies[str[i]] = 1;
        } else {
            frequencies[str[i]]++;
        }
    }
    return frequencies;
};

bool hasEnoughStrings(unordered_map<string, int> magazineFreq, unordered_map<string, int> ransomFreq) {
    bool allExist = true;
    for (auto itr = ransomFreq.begin(); itr != ransomFreq.end(); ++itr) {
        if (magazineFreq.find(itr->first) == magazineFreq.end() || magazineFreq[itr->first] < itr->second) {
            allExist = false;
            break;
        }
    }
    return allExist;
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string, int> magazineFreq = getStringFrequency(magazine);
    unordered_map<string, int> ransomFreq = getStringFrequency(ransom);
    return hasEnoughStrings(magazineFreq, ransomFreq);
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
        cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
        cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
