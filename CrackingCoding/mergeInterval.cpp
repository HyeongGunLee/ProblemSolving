#include <iostream>
#include <vector>
using namespace std;


///  Merge Intervals
struct Interval {
    int start;
    int end;
};


vector<Interval> merge(vector<Iinterval>& intervals) {
    if (intervals.empty()) return vector<Interval>{};

    vector<Interval> res;
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
        return a.start < b.start;
    });

    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (res.back().end < intervals[i].start)
            res.push_back(intervals[i]);
        else
            res.back().end = max(res.back().end, intervals[i].end);
    }
    return res;
}


int main(void) {

}