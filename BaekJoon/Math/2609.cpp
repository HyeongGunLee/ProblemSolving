#include <iostream>
using namespace std;



int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}


int lcm(int a, int b, int gcdNum) {
	return (a * b) / gcdNum;
}



int main(void) {
	int a, b;
	cin >> a >> b;
	int gcdNum = gcd(a, b);
	cout << gcdNum << endl;
	cout << lcm(a, b, gcdNum) << endl;
	return 0;
}
