#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
	int receptionNum;
	int repairNum;
} person;

typedef struct {
	int remain_time;
	int person_id;
} customer;

int T, N, M, K, A, B;
int reception[10], repair[10];
//int recept_remain[10], repair_remain[10];
customer recept_remain[10], repair_remain[10];
int peopleArrive[1001];
int min_time = 1001, max_time = -1;
int max_recept = -1, max_repair = -1;
person people[1001];

bool notDone() {
	for (int i = 0; i < K; i++) {
		if (people[i].receptionNum == -1 || people[i].repairNum == -1) {
			return true;
		}
	}
	return false;
}

void carRepair() {
	queue<int> receptQ;  // store an index of person waiting reception
	queue<int> repairQ;  // store an index of person waiting repairment
	int time = min_time;
	while (time <= (max_time + max_recept + max_repair) || !receptQ.empty() || !repairQ.empty() || notDone()) {
		for (int i = 0; i < K; i++) {
			if (peopleArrive[i] == time) {
				receptQ.push(i); // push person's index into receptQ
			}
		}

		// Reception Desk
		for (int i = 0; i < N; i++) {
			if (recept_remain[i].remain_time == 0) { // reception is available at index i
				if (recept_remain[i].person_id != -1) {
					int recept_done = recept_remain[i].person_id;
					repairQ.push(recept_done);
					recept_remain[i].person_id = -1;
				}

				if (!receptQ.empty()) {
					int cur_person = receptQ.front();
					receptQ.pop();
					people[cur_person].receptionNum = i;
					recept_remain[i].person_id = cur_person;
					recept_remain[i].remain_time = reception[i]; // set new person's remain job for reception
				}
			}
			else {
				continue;
			}
		}


		// Repair Desk
		for (int i = 0; i < M; i++) {
			if (repair_remain[i].remain_time == 0) { //repair is available at index i
				if (repair_remain[i].person_id != -1) {
					repair_remain[i].person_id = -1;
				}

				if (!repairQ.empty()) {
					int cur_person = repairQ.front();
					repairQ.pop();
					people[cur_person].repairNum = i;
					repair_remain[i].remain_time = repair[i]; // set new person's remain job for repair
					repair_remain[i].person_id = cur_person;
				}
			}
			else {
				continue;
			}
		}

		for (int i = 0; i < N; i++) {
			if (recept_remain[i].remain_time != 0) {
				recept_remain[i].remain_time--;
			}
		}

		for (int j = 0; j < M; j++) {
			if (repair_remain[j].remain_time != 0) {
				repair_remain[j].remain_time--;
			}
		}
		time++;
	}
}

int countCustomer() {
	int sum = 0;
	for (int i = 0; i < K; i++) {
		if (people[i].receptionNum == A - 1 && people[i].repairNum == B - 1) {
			sum += (i + 1);
		}
	}
	if (sum == 0) {
		return -1;
	}
	return sum;
}

int main(void) {
	cin >> T;
	int cur = 1;
	while (T > 0) {
		cin >> N >> M >> K >> A >> B;
		min_time = 1001, max_time = -1;
		max_recept = -1, max_repair = -1;

		for (int i = 0; i < 1001; i++) {
			recept_remain[i].person_id = -1;
			recept_remain[i].remain_time = 0;
			repair_remain[i].person_id = -1;
			repair_remain[i].remain_time = 0;
			people[i].receptionNum = -1;
			people[i].repairNum = -1;
		}

		for (int i = 0; i < N; i++) {
			cin >> reception[i];
			max_recept = max(max_recept, reception[i]);
		}

		for (int i = 0; i < M; i++) {
			cin >> repair[i];
			max_repair = max(max_repair, repair[i]);
		}

		for (int i = 0; i < K; i++) {
			cin >> peopleArrive[i];
			min_time = min(min_time, peopleArrive[i]);
			max_time = max(max_time, peopleArrive[i]);
		}

		carRepair();
		cout << "#"<< cur << " " << countCustomer() << endl;
		cur++;
		T--;
	}
}


