#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
	int distance;
} person;

typedef struct {
	int x;
	int y;
	int value;
	int use_arr[3];
} stair;

int min_time = 98765431;
int p_size;
int done;
int caseNum = 1;
int T, N;
int office[10][10];
vector<person> p_list;
vector<stair> s_list;
vector<person> first_s;
vector<person> second_s;

bool allDone() {
	if (p_size == done) {
		return true;
	}
	return false;
}

void getDown(queue<person>& first_q, queue<person>& second_q) {
	for (int i = 0; i < 3; i++) {
		if (s_list[0].use_arr[i] != -1) {
			s_list[0].use_arr[i]--;
			if (s_list[0].use_arr[i] == 0) {
				done++;
			}
		}

		if (s_list[1].use_arr[i] != -1) {
			s_list[1].use_arr[i]--;
			if (s_list[1].use_arr[i] == 0) {
				done++;
			}
		}
	}
	// if stair is available, process person in f_q & s_q, using count--;
	for (int i = 0; i < 3; i++) {
		if (s_list[0].use_arr[i] == -1 && !first_q.empty()) {
			first_q.pop();
			s_list[0].use_arr[i] = s_list[0].value-1;
		}

		if (s_list[1].use_arr[i] == -1 && !second_q.empty()) {
			second_q.pop();
			s_list[1].use_arr[i] = s_list[1].value-1;
		}
	}


}

void calcTime() {
	// calculate minimum time when we have a list of person for each stair
	// 1. calc distance between stair and each person for the stair
	int f_size = first_s.size();
	int s_size = second_s.size();
	int max_distance = -1;
	for (int i = 0; i < f_size; i++) {
		first_s[i].distance = abs(first_s[i].x - s_list[0].x) + abs(first_s[i].y - s_list[0].y);
		max_distance = max(max_distance, first_s[i].distance);
	}

	for (int i = 0; i < s_size; i++) {
		second_s[i].distance = abs(second_s[i].x - s_list[1].x) + abs(second_s[i].y - s_list[1].y);
		max_distance = max(max_distance, second_s[i].distance);
	}

	queue<person> first_q;
	queue<person> second_q;
	int cur_time = 1;
	while (true) {

		if (allDone()) {
			min_time = min(min_time, cur_time);
			break;
		}

		// get down to the stair
		getDown(first_q, second_q);



		// enque if it gets to the stair
		for (int i = 0; i < f_size; i++) {
			if (first_s[i].distance == cur_time) {
				first_q.push(first_s[i]);
			}
		}

		for (int i = 0; i < s_size; i++) {
			if (second_s[i].distance == cur_time) {
				second_q.push(second_s[i]);
			}
		}
		cur_time++;
	}
}

void findMinTime(int cur) {
	if (cur == p_size) {
		done = 0;
		for (int i = 0; i < 3; i++) {
			s_list[0].use_arr[i] = -1;
			s_list[1].use_arr[i] = -1;
		}
		calcTime();
		return;
	}

	first_s.push_back(p_list[cur]);
	findMinTime(cur + 1);
	first_s.pop_back();
	second_s.push_back(p_list[cur]);
	findMinTime(cur + 1);
	second_s.pop_back();
}

int main(void) {
	
	cin >> T;
	int cur = 1;
	while (T > 0) {
		cin >> N;
		p_list = {};
		s_list = {};
		min_time = 987654321;
		done = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> office[i][j];
				if (office[i][j] == 1) { // person
					person p_temp = { i, j, -1 };
					p_list.push_back(p_temp);
				}
				else if (office[i][j] != 0) {
					stair s_temp = { i, j, office[i][j], {-1, -1, -1} };
					s_list.push_back(s_temp);
				}
			}
		}
		p_size = p_list.size();
		findMinTime(0);
		cout << "#" << cur << " " << min_time << endl;
		cur++;
		T--;
	}
}



