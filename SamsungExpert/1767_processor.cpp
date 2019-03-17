#include <iostream>
using namespace std;

typedef struct Core{
    int row;
    int col;
} Core;

int T;
int N;
int core_size;
int processor[12][12];
int cableLen[13];
int MAX_SIZE = 987654321;
Core* cores[12];

void initProcessor() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            processor[i][j] = 0;
        }
    }

    for (int i = 0; i < 12; i++) {
        cores[i] = nullptr;
    }
}

void printProcessor(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << processor[i][j];
        }
        cout << endl;
    }
}

void setEnv() {
    for (int i = 0; i < 13; i++) {
        cableLen[i] = MAX_SIZE;
    }
}

bool isEnd(int cur_core) {
    int row = cores[cur_core]->row;
    int col = cores[cur_core]->col;
    if (row == 0 || row == N-1 || col == 0 || col == N-1) {
        return true;
    }
    return false;
}

bool canMove(int direct, int cur_core) { // can move to direction i from cur_core
    // N, E, S, W
    int row = cores[cur_core]->row;
    int col = cores[cur_core]->col;
    if (direct == 0) { // N
        for (int i = 0; i < row; i++) {
            if (processor[i][col] != 0) {
                return false;
            }
        }
        return true;
    } else if (direct == 1) { // E
        for (int i = col+1; i < N; i++) {
            if (processor[row][i] != 0) {
                return false;
            }
        }
        return true;
    } else if (direct == 2) { // S
        for (int i = row+1; i < N; i++) {
            if (processor[i][col] != 0) {
                return false;
            }
        }
        return true;
    } else if (direct == 3) { // W
        for (int i = 0; i < col; i++) {
            if (processor[row][i] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}


void setCable(int direct, int cur_core) { // set cable on the processor
    int row = cores[cur_core]->row;
    int col = cores[cur_core]->col;

    if (direct == 0) { // N
        for (int i = 0; i < row; i++) {
            processor[i][col] = 2;
        }
    } else if (direct == 1) { // E
        for (int i = col+1; i < N; i++) {
            processor[row][i] = 2;
        }
    } else if (direct == 2) { // S
        for (int i = row+1; i < N; i++) {
            processor[i][col] = 2;
        }
    } else if (direct == 3) { // W
        for (int i = 0; i < col; i++) {
            processor[row][i] = 2;
        }
    }
}

void unsetCable(int direct, int cur_core) {
    int row = cores[cur_core]->row;
    int col = cores[cur_core]->col;

    if (direct == 0) { // N
        for (int i = 0; i < row; i++) {
            processor[i][col] = 0;
        }
    } else if (direct == 1) { // E
        for (int i = col+1; i < N; i++) {
            processor[row][i] = 0;
        }
    } else if (direct == 2) { // S
        for (int i = row+1; i < N; i++) {
            processor[i][col] = 0;
        }
    } else if (direct == 3) { // W
        for (int i = 0; i < col; i++) {
            processor[row][i] = 0;
        }
    }
}

int getCable(int direct, int cur_core) { // get cable from cur_core to direction i
    int row = cores[cur_core]->row;
    int col = cores[cur_core]->col;

    if (direct == 0) {  // N
        return row;
    } else if (direct == 1) { // E
        return N-1-col;
    } else if (direct == 2) { // S
        return N-1-row;
    } else if (direct == 3) { // W
        return col;
    }
    return 0;
}

void getMinCableHelp(int cur_core, int core_len, int cable_len) {
    if (cur_core >= core_size) { //
        cableLen[core_len] = min(cableLen[core_len], cable_len);
//        cout << "Core Len == " << core_len << "  Cable Len == " << cable_len << endl;
//        printProcessor(N);
        return;
    }

    if (isEnd(cur_core)) {
        getMinCableHelp(cur_core+1, core_len+1, cable_len);
    }

    for (int i = 0; i < 4; i++) {
        if (canMove(i, cur_core)) {
            int cable = getCable(i, cur_core);
            setCable(i, cur_core);
            getMinCableHelp(cur_core+1, core_len+1, cable_len + cable);
            unsetCable(i, cur_core);
        }
    }

    getMinCableHelp(cur_core+1, core_len, cable_len);
}


int findMin() {
    int maxCore = -1;
    for (int i = 0; i < 13; i++) {
        if (cableLen[i] != MAX_SIZE) {
            maxCore = max(maxCore, i);
        }
    }
//    cout << "MAxCore: " <<  maxCore << endl;
    return cableLen[maxCore];
}

int getMinCable() {
    // need init
    setEnv();
//    for (int i = 0; i < N; i++) {
//        cout << "Core " << i << ": "<< cores[i]->row << " " << cores[i]->col << endl;
//    }
    getMinCableHelp(0, 0, 0);
    int result = findMin();
    return result;
}


int main(void) {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        initProcessor();
        core_size = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> processor[i][j];
                if (processor[i][j] == 1 && i != 0 && i != N-1 && j != 0 && j != N-1) {
                    Core* temp = new Core;
                    temp->col = j;
                    temp->row = i;
                    cores[core_size++] = temp;
                }
            }
        }
        int result = getMinCable();
        cout << "#" << i+1 << " " << result << endl;
//        printProcessor(N);
    }
    return 0;
}
