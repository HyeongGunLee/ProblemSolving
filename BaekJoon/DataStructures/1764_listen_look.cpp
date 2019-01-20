#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    int N, M;
    cin >> N >> M;
    map<string, int> db;
    vector<string> result;
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        db.insert(make_pair(temp, 1));
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (db.find(temp) != db.end()) {
            result.push_back(temp);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto x : result) {
        cout << x << endl;
    }
}
