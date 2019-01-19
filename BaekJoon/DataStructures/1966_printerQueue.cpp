#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T;

struct Document {
    int pos;
    int val;
};

bool isHighest(queue<Document> q) {
    int qLen = q.size();
    int temp = q.front().val;
    q.push(q.front());
    q.pop();
    for (int i = 0; i < qLen-1; i++) {
        if (temp < q.front().val) {
            return false;
        }
        q.push(q.front());
        q.pop();
    }
    return true;
}

void printQ(queue<Document>& q, vector<int>& result, int find) {
    while (!q.empty()) {
        if (isHighest(q)) {
            result.push_back(q.front().pos);
            if (q.front().pos == find) {
                return;
            }
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
    }
}


int main(void) {
    cin >> T;
    int N, M;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        queue<Document> q;
        vector<int> result;
        Document temp;
        int val;
        int pos = 0;
        for (int j = 0; j < N; j++) {
            cin >> val;
            temp.pos = pos;
            temp.val = val;
            q.push(temp);
            pos++;
        }
        printQ(q, result, M);
        cout << result.size() << endl;
    }
}
