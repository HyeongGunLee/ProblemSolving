

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS] = {
        " asdf",
        "sdfad",
};


// check all the clocks are 12
bool areAligend(const vector<int>& clocks);

//swtch꺼 푸쉬
void push(const vector<int>& clocks, int swtch) {
    for (int i = 0; i < CLOCKS; ++i) {
        if (linked[swtch][i] == 'x') {
            clocks[i] += 3;
            if(clocks[i] == 15) clocks[i] = 3;
        }
    }
}


/*
 *  clocks: status of current clock
 *  swtch: num of swtch to push
 *  return min or INF if not possible
 */

int solve(vector<int>& clocks, int swtch) {
    if (swtch == SWITCHES) return areAligend(clocks) ? 0 : INF;
    int ret = INF;
    for(int cnt = 0; cnt < 4; ++cnt) {
        ret = min(ret, cnt + solve(clocks, swtch+1));
        push(clocks, swtch); // 4times = 0 time
    }
    return swtch;
}