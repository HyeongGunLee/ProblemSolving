#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, back;
    int MAX_SIZE;

public:
    CircularQueue(int max_size = 10);
    void enqueue(int data);
    int dequeue();
    void display();
};


CircularQueue::CircularQueue(int max_size){
    MAX_SIZE = max_size;
    arr = new int[MAX_SIZE];
    front, back =  -1;
    for (int i = 0; i < MAX_SIZE; i++)
        arr[i] = 0;
}


void CircularQueue::enqueue(int data) {
    if ((back+1)%MAX_SIZE == front) {
        cout << "MAX_SIZE" << end;
        return;
    }

    back = (back+1)%MAX_SIZE;
    arr[back] = data;
    if (front == -1)
        front = 0;
}

int CircularQueue::dequeue() {
    if (front == -1) {
        return NULL;
    }

    int data;
    data = arr[front];
    arr[front] = 0;
    if (front == back) {
        front = -1;
        back = -1;
    } else {
        front = (front+1)%MAX_SIZE;
    }
    return data;
}