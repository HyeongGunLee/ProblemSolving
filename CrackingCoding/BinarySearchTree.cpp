#include <iostream>
using namespace std;

// Traversal

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int data) : data(data), left(NULL), right(NULL) {}

    void insert(int value) {
        if (value <= data) {
            if (left == NULL) {
                left = new Node(value);
            } else {
                left->insert(value);
            }
        } else {
            if (right == NULL) {
                right = new Node(value);
            } else {
                right->insert(value);
            }
        }
    };

    bool find(int value) {
        if (data == value) {
            return true;
        } else if (value < data && left != NULL) {
            return left->find(value);
        } else if (value > data && right != NULL) {
            return right->find(value);
        } else {
            return false;
        }
    }

    void printInOrder() {
        if (left != NULL) {
            left->printInOrder();
        }
        cout << data << endl;
        if (right != NULL) {
            right->printInOrder();
        }
    }

    void printPreOrder() {
        cout << data << endl;
        if (left != NULL) {
            left->printPreOrder();
        }
        if (right != NULL) {
            right->printPreOrder();
        }
    }

    void printPostOrder() {
        if (left != NULL) {
            left->printPostOrder();
        }

        if (right != NULL) {
            right->printPostOrder();
        }

        cout << data << endl;
    }

};

int main(void) {
    Node* node = new Node(10);
    node->insert(5);
    node->insert(15);
    node->insert(8);
    cout << "INORDER : " << endl;
    node->printInOrder();
    cout << "PREORDER : " << endl;
    node->printPreOrder();
    cout << "POSTORDER : " << endl;
    node->printPostOrder();
}