#include <iostream>
#include <vector>
using namespace std;


int N;
int board[20][20];
int max_num = -1;
int perm_cnt = 0;

void findMax(vector<int>& direction_list, int cnt) {
    vector<int>::iterator it;
    if (cnt == 5) {
//        perm_cnt++;
//        for (it = direction_list.begin(); it != direction_list.end(); ++it) {
//            cout << *it << " ";
//        }
//        cout << endl;
        // code here
        return;
    }

    for (int i = 0; i < 4; i++) {
        direction_list.push_back(i);
        findMax(direction_list, cnt+1);
        direction_list.pop_back();
    }
}

int comb_list[4] = {0, 1, 2, 3};
int visited[4];
void combination(vector<int>& comb_list, int cnt, int cur) {
    if (cur == cnt) {
        vector<int>::iterator it;
        for (it = comb_list.begin(); it != comb_list.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            comb_list.push_back(i);
            combination(comb_list, cnt, cur+1);
            visited[i] = 0;
            comb_list.pop_back();
        }
    }

}

int main(void) {
    cin >> N;
    vector<int> direction_list;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
//
//    for (int i = 0; i < 4; i++) {
//        direction_list.push_back(i);
//        findMax(direction_list, 1);
//        direction_list.pop_back();
//    }
    for (int i = 0; i < 4; i++) {
        vector<int> comb_list;
        combination(comb_list, i, 0);
    }
    cout <<perm_cnt<< endl;
}
