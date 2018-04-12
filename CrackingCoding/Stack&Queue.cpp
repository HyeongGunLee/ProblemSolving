#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL){}
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    int peek() {
        return head->data;
    }

    void add(int data) {
        Node* node = new Node(data);
        if (tail != NULL) {
            tail->next = node;
        }
        tail = node;
        if (head == NULL) {
            head = node;
        }
    }

    int remove() {
        int data = head->data;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        return data;
    }
};

class Stack{
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    int peek() {
        return top->data;
    }

    void push(int data) {
        Node* node = new Node(data);
        node->next = top;
        top = node;
    }

    int pop() {
        int data = top->data;
        top = top->next;
        return data;
    }

};



int main(void) {
    Queue q;
    Stack st;

    q.add(1);
    q.add(2);
    q.add(3);
    st.push(1);
    st.push(2);
    st.push(3);
    for (int i = 0; i < 3; i++) {
        cout << q.peek() << endl;
        q.remove();
    }

    for (int i = 0; i < 3; i++) {
        cout << st.peek() << endl;
        st.pop();
    }


}