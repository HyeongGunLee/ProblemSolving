#include <iostream>
using namespace std;

int mirNum[5] = {0, 1, 6, 8, 9};
int mirOdd[3] = {0, 1, 8};

void printEven(int answer[], int index) {
    int temp[index+1];
    for (int i = 0; i <= index; i++) {
        if (answer[i] == 6) temp[index-i] = 9;
        else if (answer[i] == 9) temp[index-i] = 6;
        else temp[index-i] = answer[i];
    }

    for (int i = 0; i < index; i++) {
        cout << answer[i];
    }
    for (int i = 1; i <= index; i++) {
        cout << temp[i];
    }
    cout << endl;
}

void printOdd(int answer[], int index) {
    int temp[index+1];
    for (int i = 0; i <= index; i++) {
        if (answer[i] == 6) temp[index-i] = 9;
        else if (answer[i] == 9) temp[index-i] = 6;
        else temp[index-i] = answer[i];
    }

    for (int j = 0; j < 3; j++) {
        temp[0] = mirOdd[j];
        for (int i = 0; i <index; i++) {
            cout << answer[i];
        }
        for (int i = 0; i <= index; i++) {
            cout << temp[i];
        }
        cout << endl;
    }



}

void printMirror(int answer[], int index, int N) {
    int mid = N/2;

    if (N == 1) {
        for (int i = 0; i < 3; i++)
            cout << mirOdd[i];
        return;
    }


    if (index == mid) {
        if (N%2 == 0) {
            printEven(answer, index);
        } else {
            printOdd(answer, index);
        }
        return;
    }

    if (index == 0) {
        for (int i = 1; i < 5; i++) {
            answer[index] = mirNum[i];
            printMirror(answer, index+1, N);
        }
    } else {
        for (int i = 0; i < 5; i++) {
            answer[index] = mirNum[i];
            printMirror(answer, index+1, N);
        }
    }
}

int main(void) {
    int answer[1] = {};
    printMirror(answer, 0, 1);
}