/*
 *  RedBlackTree
 *
 */

enum Color {RED, BLACK};

template <typename E>
class RBEntry : public E {
private:
    Color col;
protected:
    Key K;
    Value V;
    Color color() const { return col;}
    bool isRed() const { return col == RED;}
    bool isBlack() const { return col == BLACK;}
    void setColor(Color c) { col = c;}
public:
    RBEntry(const K& k = K(), const V& v = V()) : E(k, v), col(BLACK) {
    }
    friend class RBTree<E>;
};

template <typename E>
class RBTree{
public:
    typedef RBEntry<E> RBEntry;
    typedef typename SearchTree<RBEntry>::Iterator Iterator;
protected:
    RBEntry::Key K;
    RBEntry::Value V;
    SearchTree<RBEntry> ST;
    ST::TPos TPos;
public:
    RBTree();
    Iterator insert(const K& k, const V& x);
    void erase(const K& k);
    void erase(const Iterator& p);
protected:
    void remedyDoubleRed(const TPos& z);
    void remedyDoubleBlack(const TPos& r);

};

Iterator insert(const K& k, const V& x) {
    TPos v = inserter(k, x);
    if (v == ST::root())
        setBlack(v);
    else {
        setRed(v);
        remedyDoubleRed(v);
    }
    return Iterator(v);
}

void remedyDoubleRed(const Tpos& z) {
    TPos v = z.parent();
    if (v == ST::root() || v->isBlack()) return;
    if (sibling(v)->isBlack()) {
        v = reconstruct(z);
        setBlack(v);
        setRed(v.left()); setRed(v.right());
    }
    else {
        setBlack(v); setBlack(sibling(v));
        TPos u = v.parent();
        if (u == ST::root()) return;
        setRed(u);
        remedyDoubleRed(u);
    }
}

void erase(const K& k) {
    TPos u = finder(K, ST::root());
    if (Iterator(u) == ST::end())
        return;
    TPos r = eraser(u);
    if (r == ST::root() || r->isRed() || wasParentRed(r))
        setBlack(r);
    else
        remedyDoubleBlack(r);
}

void remedyDoubleBlack(const TPos& r) {
    TPos x = r.parent();
    TPos y = sibling(r);
    if (y->isBlack()) {
        if (y.left()->isRed() || y.right()->isRed()) {
            TPos z = (y.left()->isRed() ? y.left() : y.right());
            Color topColor = x->color();
            z = restructure(z);
            setColr(z, topColor);
            setBlack(r);
            setBlack(z.left()); setBlack(z.right());
        }
    }
}

