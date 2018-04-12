/*
 *  Priority Queue
 *      * insert(e), min(), removeMin(),
 *      * size(), empty()
 *  * implement with a List
 *      - constant time insertion, but linear-time search and removal(O(n))
 *      - with sorted list: min, remove(O(1)), insertion: O(n)
 *  * implement with a Heap
 *      - faster than list-based implementation
 *
 *  * insertion sort
 *      - using priority queue, sorted list -> O(n + I) time, I: num of inversions
 *      - checking the element end of the priority queue
 *
 */

template <typename E, typename C>
class ListPriorityQueue {
public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    const E& min() const;
    void removeMin();
private:
    List<E> L;
    C isLess;
};

int ListPriorityQueue::size() const {
    return L.size();
}

bool ListPriorityQueue::empty() const {
    return L.empty();
}

void ListPriorityQueue::insert(const E &e) {
    list<E>::iterator p;
    p = L.begin();
    while (p != L.end() && !isLess(e, *p)) ++p;
    L.insert(p, e);
}

const E & ListPriorityQueue::min() const {
    return L.front();
}

void ListPriorityQueue::removeMin() {
    L.pop_front();
}




