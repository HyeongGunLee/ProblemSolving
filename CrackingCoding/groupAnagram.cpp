#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int strsSize = strs.size();
    unordered_map<string, int> map1;
    vector<vector<string>> result;
    int hashIndex = 0;
    result.push_back(vector<string>());
    for (int i = 0; i < strsSize; i++) {
        string temp = strs[i];
        sort(temp.begin(), temp.end());

        if (map1.find(temp) == map1.end()) {
            hashIndex++;
            map1[temp] = hashIndex;
            result.push_back(vector<string>());
            result[hashIndex].push_back(strs[i]);
        } else {
            result[map1[temp]].push_back(strs[i]);
        }
    }
    return result;
}

int main(void) {

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    for (vector<string> i : result) {
        for (string j : i) {
            cout << j <<  " ";
        }
        cout << endl;
    }
}