#:wqinclude <iostream>
using namespace std;

/*
 *  Deque can be implemented using linkedlist or circular array
 *  this Deque is implemented with circular array.
 */

class Deque {
private:
    int arr[100];
    int front;
    int rear;
    int size;

public:
    Deque(int size) {
        front = -1;
        rear = 0;
        this->size = size;
    };
    bool empty() const;
    bool full() const;
    const int getFront() const;
    const int getRear() const;
    void insertFront(const int data);
    void insertBack(const int data);
    void removeFront();
    void removeBack();

};

bool Deque::empty() const {
    return (front == -1);
}

bool Deque::full() const {
    return ((front == 0 && rear == size -1) || front == rear+1);
}

void Deque::insertFront(const int data) {
    if (full()) {
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front = front - 1;
    }
    arr[front] = data;
}

void Deque::insertBack(const int data) {
    if (full()) {
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear = size-1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    arr[rear] = data;
}

void Deque::removeBack() {
    if (empty()) {
        return;
    }

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear = rear - 1;
    }
}

void Deque::removeFront() {
    if (empty()) {
        return;
    }

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == size - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }
}

const int Deque::getFront() const {
    if (empty()) {
        return -1;
    }
    return arr[front];
}

const int Deque::getRear() const {
    if (empty()) {
        return -1;
    }
    return arr[rear];
}


int main(void) {

}
