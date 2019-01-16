#include <iostream>
using namespace std;

typedef int Elem;

class Queue {
public:
    Queue(int size=10);
    ~Queue();
    int size() const;
    bool empty();
    Elem front() const;
    void enqueue(Elem e);
    void dequeue();
private:
    int f;
    int r;
    int n;
    int *arr;
};


Queue::Queue(int size){
    arr = new int[size];
    n = 0;
    f = -1;
    r = 0;
}

Queue::~Queue() {
    delete arr;
}

int Queue::size() const {
    return n;
}

bool Queue::empty() {
    return n == 0;
}

Elem Queue::front() const {
    if (n == 0) {
        return -1;
    }
    return arr[f];
}

void Queue::enqueue(Elem e) {
    if (size() == 100) {
        return;
    }
    arr[r] = e;
    r = (r + 1) % 100;
    n += 1;
}

void Queue::dequeue() {
    if (n == 0) {
        return;
    }
    f = (f+1) % 100;
    n -= 1;
}

