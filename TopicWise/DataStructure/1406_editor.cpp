#include <iostream>
#include <list>
#include <string>
using namespace std;

string arr;
int N;
list<char> editor;

int main(void) {
    list<char>::iterator it;

    cin >> arr;
    cin >> N;

    for (int i = 0; i < arr.size(); i++)
        editor.push_back(arr[i]);

    it = editor.end();

    for (int i = 0; i < N; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'P') {
            char x;
            cin >> x;
            editor.insert(it, x);
        } else if (cmd == 'L') {
            if (it != editor.begin())
                --it;
        } else if (cmd == 'D') {
            if (it != editor.end())
                ++it;
        } else if (cmd == 'B') {
            if (it != editor.begin()) {
                --it;
                it = editor.erase(it);
            }
        }
    }

    for (it = editor.begin(); it != editor.end(); ++it) {
        cout << *it;
    }
}