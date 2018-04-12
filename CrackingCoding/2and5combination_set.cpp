#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


void output(int N) {
    set<int> contain;
    contain.insert(1);
    for (int i = 2; i <= N; i++) {
        if ((i % 2 == 0 && (contain.find(i/2) != contain.end())) || (i%5 == 0 && (contain.find(i/5) != contain.end()))) {
            contain.insert(i);
            cout<< i << endl;
        }
    }
}

int main(void) {
    output(25);

}