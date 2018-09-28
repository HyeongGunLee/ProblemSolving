#include <iostream>
#include <vector>
using namespace std;

int N;
int max_num = -1000000001;
int min_num = 1000000001;
vector<int> numList;
vector<char> operList;
bool isUsed[12];
char curOpers[12];
char ops[4] = {'+', '-', '*', '/'};

void calculate() {
    int result =numList[0];
    for (int i = 0; i < N-1; i++) {
        if (curOpers[i] == '+') {
            result += numList[i+1];
        } else if (curOpers[i] == '-') {
            result -= numList[i+1];
        } else if (curOpers[i] == '*') {
            result *= numList[i+1];
        } else if (curOpers[i] == '/') {
            result /= numList[i+1];
        }
    }
    max_num = max(max_num, result);
    min_num = min(min_num, result);
}


void dfs(int cur) {
    if (cur == N-1) {
        calculate();
        return;
    }

    for (int i = 0; i < N-1; i++) {
        if (!isUsed[i]) {
            isUsed[i] = 1;
            curOpers[cur] = operList[i];
            dfs(cur+1);
            isUsed[i] = 0;
        }
    }
}


int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        numList.push_back(temp);
    }
    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            operList.push_back(ops[i]);
        }
    }

    dfs(0);
    cout << max_num << endl;
    cout << min_num << endl;
}
