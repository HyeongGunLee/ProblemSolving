#include<iostream>
using namespace std;


int magnet[4][8];
bool visited[4];


void shift(int magNum, int direction) {
    if (direction == 1) {
        int temp = magnet[magNum][7];
        for (int i = 7; i > 0; i--) {
            magnet[magNum][i] = magnet[magNum][i-1];
        }
        magnet[magNum][0] = temp;
    } else {
        int temp = magnet[magNum][0];
        for (int i = 0; i < 7; i++) {
            magnet[magNum][i] = magnet[magNum][i+1];
        }
        magnet[magNum][7] = temp;
    }
}

void solve(int magNum, int direction) {
    visited[magNum] = true;
    if (magNum < 3 && magnet[magNum][2] != magnet[magNum+1][6] && !visited[magNum+1]) {
        solve(magNum+1, -1 * direction);
    }

    if (magNum > 0 && magnet[magNum][6] != magnet[magNum-1][2] && !visited[magNum-1]) {
        solve(magNum-1, -1 * direction);
    }
    shift(magNum, direction);
}

int caculateSum() {
    int sum = 0;
    int x = 1;
    for (int i = 0; i < 4; i++) {
        if (magnet[i][0] == 1) {
            sum += x;
        }
        x *= 2;
    }
    return sum;
}

void initVisited() {
    for (int i = 0; i < 4; i++) {
        visited[i] = false;
    }
}



int main(int argc, char** argv)
{
    int test_case;
    int T;
    int K;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> K;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> magnet[i][j];
            }
        }

        for (int i = 0; i < K; i++) {
            int num, dir;
            cin >> num >> dir;
            initVisited();
            solve(num-1, dir);
        }


        cout << "#" << test_case << " " << caculateSum() << endl;

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}