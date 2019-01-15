#include <iostream>
#include <string>
using namespace std;

typedef string Elem;

class CNode {
private:
    Elem elem;
    CNode *next;
    friend class CircleList;
};

class CircleList {
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance();
    void add(const Elem& e);
    void remove();
private:
    CNode* cursor;
};

CircleList::CircleList() {
    cursor = nullptr;
}

CircleList::~CircleList() {
    while (cursor != nullptr) {
        remove();
    }
}

bool CircleList::empty() const {
    return cursor == nullptr;
}

const Elem& CircleList::back() const {
    return cursor->elem;
}

const Elem& CircleList::front() const {
    return cursor->next->elem;
}

void CircleList::advance() {
    cursor = cursor->next;
}

void CircleList::remove() {
    CNode* old = cursor->next;
    if (old == cursor)
        cursor == nullptr;
    else
        cursor->next = old->next;
    delete old;
}

void CircleList::add(const Elem &e) {
    CNode *v = new CNode;
    v->elem = e;
    if (cursor == nullptr) {
        v->next = v;
        cursor = v;
    }
    else {
        v->next = cursor->next;
        cursor->next = v;
    }
}

int main() {
    CircleList playList; // [ ]
    playList.add("Stayin Alive"); // [Stayin Alive*]
    playList.add("Le Freak"); // [Le Freak, Stayin Alive*]
    playList.add("Jive Talkin"); // [Jive Talkin, Le Freak, Stayin Alive*]
    playList.advance(); // [Le Freak, Stayin Alive, Jive Talkin*]
    playList.advance(); // [Stayin Alive, Jive Talkin, Le Freak*]
    playList.remove(); // [Jive Talkin, Le Freak*]
    playList.add("Disco Inferno"); // [Disco Inferno, Jive Talkin, Le Freak*]
    for (int i = 0; i < 5; i++) {
        cout << playList.front() << endl;
        playList.advance();
    }
    return 0;
}
