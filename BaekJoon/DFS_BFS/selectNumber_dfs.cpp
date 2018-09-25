#include <vector>
#include <iostream>
using namespace std;

int N;
bool visited[100];
vector<int> resultList;
int start;

void dfs(vector<int>& num_list, int x) {
    if (!visited[num_list[x]]) {
        visited[num_list[x]] = 1;
        dfs(num_list, num_list[x]);
        visited[num_list[x]] = 0;
    }

    if (num_list[x] == start) {
        resultList.push_back(start);
    }
}



int main(void) {
    cin >> N;
    vector<int> num_list(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> num_list[i];
    }

    for (int i = 1; i <= N; i++) {
        visited[i] = 1;
        start = i;
        dfs(num_list, i);
        visited[i] = 0;
    }

    int resultLen = resultList.size();
    cout << resultLen << endl;
    for (int i = 0; i < resultLen; i++) {
        cout << resultList[i] << endl;
    }
}
