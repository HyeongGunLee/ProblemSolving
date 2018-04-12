/*
 * Doublely linked list - constant time for insert and delete
 * empty()
 * front()
 * back()
 * addFront() O(1)
 * addBack() O(1)
 * removeFront() O(1)
 * removeBack() O(1),
 * begin(), end()
 * atIndex: O(n)
 *
 *  * Iterator
 */

#include <iostream>
#include <vector>
using namespace std;


typedef string Elem;

struct DNode{
    Elem elem;
    DNode *next;
    DNode *prev;
};

class DLinkedList{
public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();
    Iterator begin() const;
    Iterator end() const;
protected:
    void add(DNode* v, const Elem& e);
    void remove(DNode* v);
private:
    DNode *header;
    DNode *trailer;
};

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while(!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const {
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const {
    return header->next->elem;
}

const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}


void DLinkedList::add(DNode *v, const Elem &e) {
    DNode* u = new DNode;
    u->elem = e;
    u->next = v->next;
    u->prev = v->prev;
    v->prev = u;
    v->prev->next = u;
}

void DLinkedList::addFront(const Elem &e) {
    add(header->next, e);
}

void DLinkedList::addBack(const Elem &e) {
    add(trailer, e);
}

void DLinkedList::remove(DNode *v) {
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

void DLinkedList::removeFront() {
    remove(header->next);
}

void DLinkedList::removeBack() {
    remove(trailer->prev);
}

Iterator DLinkedList::begin() const {
    return (Iterator(header->next));
}

Iterator DLinkedList::end() const {
    return Iterator(trailer);
}

void listReverse(DLinkedList& L) {
    DLinkedList T;
    while (!L.empty()) {
        string s = L.front();
        L.removeFront();
        T.addFront(s);
    }
    while (!T.empty()) {
        string s = T.front();
        T.removeFront();
        L.addBack(s);
    }
}



class Iterator {
public:
    Elem& operator*();
    bool operator==(const Iterator& p) const;
    bool operator!=(const Iterator& p) const;
    Iterator& operator++();
    Iterator& operator--();
    friend class DLinkedList();
private:
    DNode* v;
    Iterator(Node* u); //Private Constructor
};

DLinkedList::Iterator::Iterator(Node* u)
{
    v = u;
}

DLinkedList::Iterator::operator*()
{
    return v->elem;
}

DLinkedList::Iterator::operator==(const Iterator& p) const
{
    return v == p.v;
}

DLinkedList::Iterator::operator++(){
    v = v->next;
    return *this;
}

int main(void)
{
    vector<vector<int>> M(n, vector<int>(m));
}