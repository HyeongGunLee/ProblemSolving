#include <iostream>
using namespace std;

typedef string Elem;

class DNode {
private:
    Elem elem;
    DNode* prev;
    DNode* next;
    friend class DLinkedList;
};

class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem& front() const;
    const Elem& end() const;
    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();
private:
    DNode *header;
    DNode *tailer;
protected:
    void add(DNode* v, const Elem& e);
    void remove(DNode* v);
};

DLinkedList::DLinkedList() {
    header = new DNode();
    tailer = new DNode();
    header->next = tailer;
    tailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete tailer;
}

bool DLinkedList::empty() const {
    return header->next == tailer;
}

const Elem& DLinkedList::front() const {
    return header->next->elem;
}

const Elem& DLinkedList::end() const {
    return tailer->prev->elem;
}


void DLinkedList::add(DNode *v, const Elem &e) {
    DNode *u = new DNode;
    u->elem = e;

    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
}

void DLinkedList::addFront(const Elem &e) {
    add(header->next, e);
}

void DLinkedList::addBack(const Elem &e) {
    add(tailer, e);
}

void DLinkedList::remove(DNode* v) {
    DNode *u = v->prev;
    DNode *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront() {
    remove(header->next);
}

void DLinkedList::removeBack() {
    remove(tailer->prev);
}