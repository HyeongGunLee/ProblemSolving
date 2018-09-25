#include <iostream>
#include <vector>
#include <set>
using namespace std;


int N;
set<int> indexSet;
set<int> numberSet;
set<int> resultSet;

int visited[101] = {0, };
void numberSelect(vector<int>& num_list, int cur, int cnt) {
    if (cur == cnt && indexSet == numberSet) {
        resultSet = numberSet;
        return;
    }

    for (int i = cur; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            indexSet.insert(i+1);
            numberSet.insert(num_list[i]);
            numberSelect(num_list, i, cnt+1);
            indexSet.erase(i+1);
            numberSet.erase(num_list[i]);
            visited[i] = 0;
        }
    }
}

int main(void) {
    cin >> N;
    vector<int> num_list(N);
    for (int i = 0; i < N; i++) {
        cin >> num_list[i];
    }
    for (int i = N; i > 0; --i) {
        numberSelect(num_list, 0, i);
    }
    cout << resultSet.size() << endl;
    set<int>::iterator it;
    for (it = resultSet.begin(); it != resultSet.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
