#include <iostream>
#include <algorithm>
using namespace std;

int T, ticket[4], plan[12];
int min_value = 987654321;

void findMinPrice(int curMonth, int curPrice) {
	if (curMonth > 11) {
		if (curPrice > 0) {
			min_value = min(min_value, curPrice);
		}
		return;
	}

	int plan_num = plan[curMonth];
	int price = plan_num * ticket[0];
	findMinPrice(curMonth + 1, curPrice + price);
	if (plan[curMonth] != 0) {
		price = ticket[1];
		findMinPrice(curMonth + 1, curPrice + price);
	}
	price = ticket[2];
	findMinPrice(curMonth + 3, curPrice + price);
}

int main(void) {
	cin >> T;
	int cur = 1;
	while (T > 0) {
		min_value = 987654321;
		for (int i = 0; i < 4; i++) {
			cin >> ticket[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> plan[i];
		}
		min_value = ticket[3];
		findMinPrice(0, 0);
		cout << "#" << cur << " " << min_value << endl;
		cur++;
		T--;
	}

}


