#include <iostream>
#include <cstring>
using namespace std;

char arr[10000];
bool char_set[256];

bool isUnique(char str[]) {
    if (strlen(str) > 256) return false;

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        int val = str[i];
        if (char_set[str[i]])
            return false;
        char_set[val] = true;
    }
    return true;
}

int main(void) {
    cin >> arr;
    cout << isUnique(arr) << endl;
}