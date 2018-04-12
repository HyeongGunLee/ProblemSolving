/*
 * Binary Tree
 *  - p.left(), p.right(), p.parent(),
 *  - P.isExternal(), p.isRoot()
 *  - size(), empty(), root(), positions()
 *
 *   * Linked Structure
 *      - parent, left, right & Element
 *      - tree's size, pointer to the root
 *
 *  * Vector-Based Structure
 *      - if v is the root of T, then f(v) = 1
 *      - if v is the left child of node u, then f(v) = 2f(u)
 *      - if v is the right childe of node u, then f(v) = 2f(u) + 1
 *
 *  * Postorder traversal of a binary tree can be used to solve
 *    the expression evaluation problem: O(n)
 *
 *  * Inorder(T, p):
 *      if p is an internal node then
 *          inorder(T, p.left())
 *      perform the "visit" action for node p
 *      if p is an internal node then
 *          inorder(T, p.right())
 */


typedef string Elem;




typedef list<Position> PositionList;

class LinkedBinaryTree {
protected:
    struct Node{
        Elem elt;
        Node* parent;
        Node* right;
        Node* left;
        Node() : elt(), parent(NULL), right(NULL), left(NULL) {}
    };
public:
    // Position in the tree
    class Position{
    private:
        Node* v;
    public:
        Position(Node* _v = NULL) : v(_v){}
        Elem& operator*()
        { return v->elt;}
        Positon left() const {
            return Position(v->left);
        }
        Position right() const {
            return Position(v->right);
        }
        Position parent() const {
            return Position(v->parent);
        }

        bool isRoot() const {
            return v->parent == NULL;
        }

        bool isExternal() const {
            return v->left == NULL && v->right == NULL;
        }
        friend class LinkedBinaryTree;
    };
};

void LinkedBinaryTree::expandExternal(const Position& p)
{
    Node* v = p.v;
    v->left = new Node;
    v->right = new Node;
    v->left->parent = v;
    v->right->parent = v;
    n += 2;
}


/*
 * remove p and parent
 */
LinkedBinaryTree::Position LinkedBinaryTree::removeAboveExternal(const Position& p)
{
    Node* w = p.v;
    Node* v = w->parent;
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {
        _root = sib;
        sib->parent = NULL;
    }
    else {
        Node* gpar = v->parent;
        if (v == gpar->left) gpar-left = sib;
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w; delete v;
    n -= 2;
    return Position(sib);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

void LinkedBinaryTree::preorder(Node* v, Position& pl) const {
    pl.push_back(Position(v));
    if (v->left != NULL)
        preorder(v->left, pl);
    if (v->right != NULL)
        preorder(v->right, pl);
}




