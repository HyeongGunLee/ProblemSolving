/*
 * Stack
 *  - can be implemented using Array, LinkedList
 *  - can be used to reverse a vector
 *      *Matching parentheses Problem
 */
#include <iostream>
#include <vector>
using namespace std;

template <typename E>
class Stack{
    enum { DEF_CAPACITY = 100};
public:
    Stack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const E& top() const; // Throw Stack empty
    void push(const E& e); // Throw StackFUll
    void pop() //Throw stack empty
private:
    E* S;
    int top;
    int capacity;
};

template <typename E>
Stack<E>::Stack(int cap) {
    S = new E[cap];
    capacity = cap;
    top = -1;
}

template <typename E>
int Stack<E>::size() const {
    return top+1;
}

template <typename E>
bool Stack<E>::empty() const {
    return (top < 0);
}

template <typename E>
const E& Stack<E>::top() const {
    if (empty()) cout << " EMpty"<<endl;
    else
        return S[top];
}

template <typename E>
void Stack<E>::push(const E &e) {
    if (size() == capacity) cout << "Full" <<endl;
    else{
        top++;
        S[top] = e;
    }
}

template <typename E>
void Stack<E>::pop() {
    if (empty()) cout << "Empty" <<endl;
    else {
        --t;
    }
}

template <typename E>
void reverse(vector<E>& v)
{
    Stack<E> S(v.size());
    for (int i=0; i < v.size(); i++) {
        S.push(v[i]);
    }
    for (int i=0; i < v.size(); i++) {
        v[i] = S.top();
        S.pop();
    }
}
