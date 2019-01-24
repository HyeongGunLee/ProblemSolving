#include <iostream>
#include <queue>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* GetNewNode(int value);
BSTNode* Insert(BSTNode* node, int value);
bool Search(BSTNode* node, int value);
void DeleteTree(BSTNode* node);
int GetMin(BSTNode* node);
int GetMax(BSTNode* node);
int GetHeight(BSTNode* node);
void PrintBFS(BSTNode* node);
void PrintInOrder(BSTNode* node);
bool IsBinarySearchTree(BSTNode* node, int min, int max);
bool IsBetween(BSTNode* node, int value);
BSTNode* DeleteValue(BSTNode* node, int value);
BSTNode* GetMinNode(BSTNode* node);
BSTNode* GetSuccessor(BSTNode* node, int value);


BSTNode* GetNewNode(int value) {
    BSTNode* nn = new BSTNode;
    nn->left = nullptr
    nn->right = nullptr;
    nn->data = value;
    return nn;
}

BSTNode* Insert(BSTNode* node, int value) {
    if (node == nullptr) {
        node = GetNewNode(value);
        return node;
    }

    if (value <= node->data) {
        node->left = Insert(node->left, value);
    } else {
        node->right = Insert(node->right, value);
    }
    return node;
}

bool Search(BSTNode* node, int value) {
    if (node == nullptr) {
        return false;
    }

    if (node->data == value) {
        return true;
    } else if (node->data > value) {
        return Search(node->left, value);
    } else {
        return Search(node->right, value);
    }
}

BSTNode* GetMinNode(BSTNode* node) {
    if (node == nullptr) {
        return node;
    }

    if (node->left == nullptr) {
        return node;
    }
    return GetMinNode(node->left);
}

int GetMin(BSTNode* node) {
    if (node == nullptr) {
        return -1;
    }

    if (node->left == nullptr) {
        return node->data;
    }
    return GetMin(node->left);
}

int GetMax(BSTNode* node) {
    if (node == nullptr) {
        return -1;
    }

    if (node->right == nullptr) {
        return node->data;
    }
    return GetMax(node->right);
}

int GetHeight(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(GetHeight(node->left), GetHeight(node->right)) + 1;
}

void DeleteTree(BSTNode* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr) DeleteTree(node->left);
    if (node->right != nullptr) DeleteTree(node->right);
    delete node;
}

void PrintBFS(BSTNode* node) {
    queue<BSTNode*> node_queue;
    BSTNode* current;

    node_queue.push(node);

    while (!node_queue.empty()) {
        current = node_queue.front();
        node_queue.pop();
        if (current != nullptr) {
            cout << current->data << " ";
            if (current->left != nullptr) node_queue.push(current->left);
            if (current->right != nullptr) node_queue.push(current->right);
        }
    }
}


void PrintInOrder(BSTNode* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr) {
        PrintInOrder(node->left);
    }
    cout << node->data << endl;
    if (node->right != nullptr) {
        PrintInOrder(node->right);
    }
}

BSTNode* DeleteValue(BSTNode* node, int value) {
    if (node == nullptr) return nullptr;

    if (value < node->data) {
        node->left = DeleteValue(node->left, value);
    } else if (value > node->data) {
        node->right = DeleteValue(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            BSTNode* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node;
            node = node->left;
            delete temp;
        } else {
            BSTNode* temp = GetMinNode(node->right);
            node->data = temp->data;
            node->right = DeleteValue(node->right, temp->data);
        }
    }
    return node;
}

BSTNode* GetSuccessor(BSTNode* node, int value) {
    if (node == nullptr) {
        return node;
    }

    BSTNode* target_node = node;
    while (target_node->data != value) {
        if (value < target_node->data) {
            target_node = target_node->left;
        } else if (target_node->data < value) {
            target_node target_node->right;
        }
    }

    if (target_node->right != nullptr) {
        return GetMinNode(target_node->right);
    } else {
        BSTNode* successor = nullptr;
        BSTNode* ancestor = node;
        while (ancestor != nullptr) {
            if (value < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
