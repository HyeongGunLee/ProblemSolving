#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H;
int ladder[30][10];
int min_line = 4;

void setLine(int index) {
	int r = index / (N - 1);
	int c = index % (N - 1);
	ladder[r][c] = 1;
}

void unsetLine(int index) {
	int r = index / (N - 1);
	int c = index % (N - 1);
	ladder[r][c] = 0;
}

bool isSameLine(int start, int row, int col, int dir) {
	if (row == H) { // get the end
		if (col == start) {
			return true;
		}
		else {
			return false;
		}
	}

	if (dir == 0) { //get down
		if (ladder[row][col] == 1 || ladder[row][col] == 2) {
			// turn right
			return isSameLine(start, row, col + 1, 1);
		}
		else if (col - 1 >= 0 && (ladder[row][col - 1] == 1 || ladder[row][col - 1] == 2)) {
			// turn left
			return isSameLine(start, row, col - 1, 2);
		}
		else {
			// get down
			return isSameLine(start, row + 1, col, 0);
		}
	}
	else if (dir == 1) { // right
		return isSameLine(start, row + 1, col, 0);
	}
	else if (dir == 2) { // left
		return isSameLine(start, row + 1, col, 0);
	}
	else {
		return false;
	}
}

bool checkLine() {
	for (int i = 0; i < N; i++) {
		//cout << "@@@@@MOVING ROW : " << i << endl;
		if (!isSameLine(i, 0, i, 0)) {
			return false;
		}
	}
	return true;
}

bool canSet(int a) {
	int r = a / (N - 1);
	int c = a % (N - 1);
	if (ladder[r][c] == 2) {
		return false;
	}

	if (ladder[r][c - 1] != 1 && ladder[r][c + 1] != 1 && ladder[r][c-1] != 2 && ladder[r][c+1] != 2) {
		return true;
	}
	return false;
}

void getMinLine() {
	// 0
	if (checkLine()) {
		min_line = 0;
		return;
	}

	// 1
	int max_line = (N - 1) * H;
	for (int i = 0; i < max_line; i++) {
		if (canSet(i)) {
			setLine(i);
			if (checkLine()) {
				min_line = min(min_line, 1);
				return;
			}
			unsetLine(i);
		}
		else {
			continue;
		}
	}

	// 2
	for (int i = 0; i < max_line-1; i++) {
		for (int j = i+1; j < max_line; j++) {
			if (canSet(i) && canSet(j)) {
				setLine(i);
				setLine(j);
				if (checkLine()) {
					min_line = min(min_line, 2);
					return;
				}
				unsetLine(i);
				unsetLine(j);
			}
			else {
				continue;
			}
		}
	}

	// 3
	for (int i = 0; i < max_line - 2; i++) {
		for (int j = 0; j < max_line - 1; j++) {
			for (int k = 0; k < max_line; k++) {
				if (canSet(i) && canSet(j) && canSet(k)) {
					setLine(i);
					setLine(j);
					setLine(k);
					if (checkLine()) {
						min_line = min(min_line, 3);
						return;
					}
					unsetLine(i);
					unsetLine(j);
					unsetLine(k);
				}
			}
		}
	}
	if (min_line == 4) {
		min_line = -1;
	}
}


int main(void) {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int row, col;
		cin >> row >> col;
		ladder[row - 1][col - 1] = 2;
	}

	getMinLine();
	cout <<  min_line << endl;
}


