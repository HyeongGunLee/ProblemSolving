/*
 *  Heap
 *      - insertion and removal in logarithmic time.
 *      - add(e), remove(), replace(), insert, remove(p)
 *      - min(): O(1), insert: O(log n), removeMin: O(log n)
 *      (heap으로 priority queue구현시 정렬이 빠름)
 *      - space O(n)
 *      - heap based implementation of Priority Queue: O(nlogn) sort
 *      is faster than List-based implementation
 *
 *  *Bottom-up Heap
 *      - if the all the elements to be stored are given
 *      - O(n) time construction
 *      - worst case: O(nlogn)
 */
#include <vector>

template <typename E>
class CompleteTree{
private:
    vector<E> V;
public:
    typedef typename vector<E>::iterator Position;
protected:
    Position pos(int i) {
        return V.begin() + i;
    }
    int idx(const Position& p) const {
        return p - V.begin();
    }

public:
    class Position;
    int size() const {return V.size() - 1};
    Position left(const Position& p) {return pos(2 * idx(p));};
    Position right(const Position& p) {return pos(2*idx(p) + 1);};
    Position parent(const Position& p) {return pos(idx(p)/2);}
    bool hasLeft(const Position& p) {return 2*idx(p) <= size();};
    bool hasRight(const Position& p) {return 2*idx(p)+1 <= size();};
    bool isRoot(const Position& p) {return idx(p) == 1};
    Position root() {return pos(1);};
    Position last() {return pos(size())};
    void addLast(const E& e) { V.push_back(e);};
    void removeLast() { V.pop_back();};
    void swap(const Position& p, const Position& q) {
        E e = *q; *q = *p; *p = e;
    };
};

template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const Elem& e)
{
    T.addLast(e);
    Position v = T.last();
    while (!T.isRoot()) {
        Position u = T.parent(v);
        if (!isLess(*u, *v)) break;
        T.swap(u, v);
        v = u;
    }
};

template <typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin()
{
    if (T.size() == 1) T.removeLast();
    else {
        Position u = T.root();
        T.swap(u, T.last());
        T.removeLast();
        while (T.hasLeft(u)) {
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u), *v)))
                v = T.right(u);
            if (isLess(*v, *u)) {
                T.swap(u, v);
                u = v;
            }
            else break;
        }
    }

};
