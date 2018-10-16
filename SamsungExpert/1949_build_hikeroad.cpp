#include <iostream>
#include <algorithm>
using namespace std;


int T, N, K;
int mountain[8][8];
int max_height = -1;
int max_path = -1;
int visited[8][8];
int direction[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool isInside(int row, int col) {
	if (row >= 0 && row < N && col >= 0 && col < N) {
		return true;
	}
	return false;
}

// try if the height of adjacent cell is equal or higher than current height
void startHike(int row, int col, int current_h, int hike_len, bool isConstruct) {
	max_path = max(max_path, hike_len);

	for (int i = 0; i < 4; i++) {
		int nr = row + direction[i][0];
		int nc = col + direction[i][1];
		if (isInside(nr, nc) && !visited[nr][nc]) {
			if (current_h > mountain[nr][nc]) { // height is lower thant current position
				visited[nr][nc] = 1;
				startHike(nr, nc, mountain[nr][nc], hike_len + 1, isConstruct);
				visited[nr][nc] = 0;
			}
			else { // height is equal or greater than current position
				if (isConstruct == 0) { // not being set yet
					for (int j = 1; j <= K; j++) {
						if ((mountain[nr][nc] - j) < current_h) {
							visited[nr][nc] = 1;
							startHike(nr, nc, mountain[nr][nc] - j, hike_len + 1, 1);
							visited[nr][nc] = 0;
						}
					}
				}
				else {
					continue;
				}
			}
		}
	}
}


void findLongestPath() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mountain[i][j] == max_height) {
				visited[i][j] = 1;
				startHike(i, j, max_height, 1, 0);
				visited[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			visited[i][j] = 0;
		}
	}
}

int main(void) {
	cin >> T;
	int cur = 1;
	while (T > 0) {
		cin >> N >> K;
		max_height = -1;
		max_path = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mountain[i][j];
				max_height = max(max_height, mountain[i][j]);
			}
		}
		findLongestPath();
		cout << "#"<< cur << " " << max_path << endl;
		T--;
		cur++;
	}

}



