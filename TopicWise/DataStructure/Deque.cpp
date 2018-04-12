/*
 * Deque
 *      - insertFront(e), insertBack(e), eraseFront(), eraseBack()
 *      - front(), back(), size(), empty()
 *      - using Doubly Linked List
 *      - efficient access at both ends of the list
 *
 */

#include "DLinkedList.cpp"
using namespace std;

typedef string Elem;
class LinkedDeque{
public:
    LinkedDeque();
    int size() const;
    bool empty() const; //throw empty
    const Elem& front() const; //throw empty
    const Elem& back() const; //throw empty
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront(); //throw empty
    void removeBack(); //throw empty
private:
    DLinkedList D;
    int n;
};

void LinkedDeque::insertFront(const Elem &e) {
    D.addFront(e);
    n++;
}

void LinkedDeque::insertBack(const Elem &e) {
    D.addBack(e);
    n++;
}

void LinkedDeque::removeFront() {
    if (empty()) cout << "empty" <<endl;
    else {
        D.removeFront();
        n--;
    }
}

void LinkedDeque::removeBack() {
    if (empty()) cout << "Empty" <<endl;
    else {
        D.removeBack();
        n--;
    }

}