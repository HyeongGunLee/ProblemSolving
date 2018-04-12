#include <iostream>
using namespace std;


int N;
int M;

void iceCream(int N, int flavor[], int M) {
    for (int i = 0; i < M; i++) {
        for (int j = i+1; j < M; j++) {
            if ((flavor[i] + flavor[j]) == N){
                cout << i+1 << " " << j+1 <<endl;
            }
        }
    }
}

int main(void) {
    cin >> N;
    cin >> M;
    int* flavor = new int[M];
    for (int i = 0; i < M; i++) {
        cin >> flavor[i];
    }
    iceCream(N, flavor, M);
}