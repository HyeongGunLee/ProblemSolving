/*
 *  Trees
 *      - p.parent(), p.children(), p.isRoot(), p.isExternal()
 *      - size(), empty(), root(), positions()
 *      - linked structure.
 *          - others = O(1) (children = O(num of children))
 *          - positions = O(N)
 *
 *   Tree Traversal
 *      - depth, height
 *      - Preorder
 *      - Postorder
 */

template <typename E> // base element type
class Position<E> { // a node position
public:
    E& operator*(); // get element
    Position parent() const; // get parent
    PositionList children() const; // get node’s children
    bool isRoot() const; // root node?
    bool isExternal() const; // external node?
};

template <typename E> // base element type
class Tree<E> {
public: // public types
    class Position; // a node position
    class PositionList; // a list of positions
public: // public functions
    int size() const; // number of nodes
    bool empty() const; // is tree empty?
    Position root() const; // get the root
    PositionList positions() const; // get positions of all nodes
};


/*
 *  Depth
 */

int depth(const Tree& T, const Position& p) {
    if (p.isRoot())
        return 0;
    else
        return (1 + depth(T, p.parent()));
}

/*
 *  Height = maximum depth of the Tree
 */

// not efficient O(n^2)
int height1(const Tree& T, const Position& p) {
    int h = 0;
    PositionList nodes = T.positions(); //All of nodes in the tree
    for (Iterator q = nodes.begin(); q != nodes.end(); ++q) {
        if (q->isExternal())
            h = max(h, depth(T, *q));
    }
}

// more efficient O(n)
int height2(const Tree& T, const Position& p)
{
    if (p.isExternal()) return 0;
    else {
        int h = 0;
        PositionList ch = p.children();
        for (Iterator q = ch.begin(); q != ch.end(); ++q) {
            h = max(h, height2(T, *q));
        }
        return 1+h;
    }
}


//Preorder
void preorderPrint(const Tree& T, const Position& p) {
    cout << *p;
    PositionList ch = p.children();
    for (Iterator q = ch.begin(); q != ch.end(); ++q) {
        cout << " ";
        preorderPrint(T, *q);
    };
};

//PostOrder
void postorderPrint(const Tree& T, const Position& p) {
    PositionList ch = p.children();
    for (Iterator q = ch.begin(); q != ch.end(); ++q) {
        postorderPrint(T, *q);
        cout << " ";
    }
    cout << *p << endl;
}