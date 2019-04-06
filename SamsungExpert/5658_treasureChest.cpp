#:winclude <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int T;
int N, K;

int getDigit(deque<char>& dq) {
    // char list to decimal
    deque<char>::iterator it;
    int digitLen = N / 4;


//    cout << "print DQ " << endl;
//    for (it = dq.begin(); it != dq.end(); ++it) {
//       cout << *it << " ";
//    }
//    cout << endl;

    vector<int> toCalcList;
    int temp;
    for (int i = 0; i < digitLen; i++) {
        char toChange = dq.back();
        dq.push_front(dq.back());
        dq.pop_back();
        if ((toChange - 0) >= 48 && (toChange - 0) <= 57) {
            toCalcList.push_back(toChange - 48);
        }
        else {
            toCalcList.push_back(toChange - 55);
        }
    }

    int result = 0;
    for (int i = 0; i < toCalcList.size(); i++) {
        result += toCalcList[i] * pow(16, i);
    }
    //cout << "REsult: " << result << endl;

    return result;
}

void generateNums(vector<deque<char>>& rock, vector<int>& numList) {
    int temp;
    vector<int>::iterator it;
    for (int i = 0; i < 4; i++) {
        temp = getDigit(rock[i]);
        bool isExists = false;
        for (int n = 0; n < numList.size(); n++) {
            if (numList[n] == temp) {
                isExists = true;
            }
        }

        if (!isExists) {
            numList.push_back(temp);
        }
    }
}

void rotateRock(vector<deque<char>>& rock) {
    char temp;
    for (int i = 0; i < 3; i++) {
        temp = rock[i].back();
        rock[i].pop_back();
        rock[i + 1].push_front(temp);
    }
    temp = rock[3].back();
    rock[3].pop_back();
    rock[0].push_front(temp);
}

int findRockNum(vector<deque<char>>& rock) {
    // list of generated number
    vector<int> numList;

    /*
    for (int i = 0; i <= K; i++) {
       generateNums(rock, numList);
       rotateRock(rock);
    }
    */
    generateNums(rock, numList);
    for (int i = 0; i < (N/4); i++) {
        rotateRock(rock);
        generateNums(rock, numList);
    }
    sort(numList.begin(), numList.end(), greater<int>());
    //reverse(numList.begin(), numList.end());


//    for (int i = 0; i < numList.size(); i++) {
//       cout << numList[i] << " ";
//    }
//    cout << endl;

    return numList[K-1];
}

int main(void) {
    cin >> T;
    for (int x = 0; x < T; x++) {
        cin >> N >> K;
        int dqLen = N / 4;
        char tmp;
        vector<deque<char>> rock(4);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < dqLen; j++) {
                scanf(" %1c", &tmp);
                rock[i].push_back(tmp);
            }
        }
        cout << "#" << x + 1 << " " << findRockNum(rock) << endl;
    }
    /*
    for (int i = 0; i < 4; i++) {
       cout << "#DEQUE - " << i << endl;
       while (!test[i].empty()) {
          cout << test[i].front() << " ";
          test[i].pop_front();
       }
       cout << endl;
    }
    */
}
