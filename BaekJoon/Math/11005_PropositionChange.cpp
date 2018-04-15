#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int N, B;

string convert(int n, int b) {
    string result;
    while (n >= b) {
        int remain = n%b;
        n /= b;
        if (remain >= 10) {
            char a = char('A' + (remain - 10));
            result += a;
        } else {
            result.append(to_string(remain));
        }
    }

    if (n >= 10) {
        char a = char('A' + (n - 10));
        result += a;
    } else {
        result.append(to_string(n));
    }

    reverse(result.begin(), result.end());
    return result;
}

int main(void) {
    cin >> N >> B;
    cout << convert(N, B);
    return 0;
}
