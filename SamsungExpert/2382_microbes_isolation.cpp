#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
    int cluster;
    int count;
    int dir;
    int prev_count;
} microbe;

int T, N, M, K;
microbe cells[101][101];
microbe next_cells[100][100];
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool isBoarder(int row, int col) {
    if (row == 0 || row == N - 1 || col == 0 || col == N - 1) {
        return true;
    }
    return false;
}

void moveMicrobe(int row, int col) {
    // move Microbe depends on their direction
    // 1. cut in half if it get to the board ( disaappear if the num of microbe is zero)
    // 2. merge if two microbes are meeting at the same cell ( change direction with max num of microbe)
    int move_dir = cells[row][col].dir;
    int nr = row + direction[move_dir-1][0];
    int nc = col + direction[move_dir-1][1];
    if (isBoarder(nr, nc)) {
        next_cells[nr][nc].cluster = cells[row][col].cluster;
        next_cells[nr][nc].count = cells[row][col].count / 2;
        next_cells[nr][nc].dir = move_dir + int(pow(-1, move_dir+1));
        next_cells[nr][nc].prev_count = next_cells[nr][nc].count;
    }
    else {
        // move and merge to next_cells
        if (next_cells[nr][nc].cluster != -1) {
            // merge
            if (next_cells[nr][nc].prev_count < cells[row][col].count) {
                next_cells[nr][nc].cluster = cells[row][col].cluster;
                next_cells[nr][nc].dir = cells[row][col].dir;
                next_cells[nr][nc].prev_count = cells[row][col].count;
            }
            next_cells[nr][nc].count += cells[row][col].count;
        }
        else {
            next_cells[nr][nc].cluster = cells[row][col].cluster;
            next_cells[nr][nc].count = cells[row][col].count;
            next_cells[nr][nc].dir = cells[row][col].dir;
            next_cells[nr][nc].prev_count = cells[row][col].count;
        }
    }
}


void initCell() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cells[i][j].cluster = -1;
            cells[i][j].count = 0;
            cells[i][j].dir = -1;
        }
    }
}

void moveClusters() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cells[i][j].cluster != -1) {
                moveMicrobe(i, j);
            }
        }
    }

    initCell();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cells[i][j].cluster = next_cells[i][j].cluster;
            cells[i][j].count = next_cells[i][j].count;
            cells[i][j].dir = next_cells[i][j].dir;
            next_cells[i][j].cluster = -1;
            next_cells[i][j].count = 0;
            next_cells[i][j].dir = -1;
            next_cells[i][j].prev_count = 0;
        }
    }
}

int calcSum() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += cells[i][j].count;
        }
    }
    return sum;
}


int main(void) {
    cin >> T;
    int cur = 1;
    while (T > 0) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cells[i][j].cluster = -1;
                cells[i][j].count = 0;
                cells[i][j].dir = -1;
                next_cells[i][j].cluster = -1;
            }
        }

        // Need to initialize
        for (int i = 0; i < K; i++) {
            int row, col, num, dir;
            cin >> row >> col >> num >> dir;
            cells[row][col].cluster = i;
            cells[row][col].count = num;
            cells[row][col].dir = dir;
        }

        for (int i = 0; i < M; i++) {
            moveClusters();
        }

        cout << "#" << cur << " " << calcSum() << endl;
        cur++;
        T--;
    }
}


