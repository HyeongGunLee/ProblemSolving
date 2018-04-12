#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> array;
    vector<int> minStack;
    int min;
    MinStack() {

    }

    void push(int x) {
        if (array.size() == 0) {
            min = x;
            array.push_back(x);
            minStack.push_back(x);
        } else {
            array.push_back(x);
            if (x < minStack.back()) {
                min = x;

                minStack.push_back(x);
            } else {
                minStack.push_back(minStack.back());
            }
        }
    }

    void pop() {

        array.pop_back();
        minStack.pop_back();
        min = minStack.back();
    }

    int top() {
        return array.back();
    }

    int getMin() {
        return min;
    }
};


int main(void) {

}