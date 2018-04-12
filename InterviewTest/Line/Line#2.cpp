#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : val(data), left(NULL), right(NULL) {}
};

int height(TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void treeLevelPrint(TreeNode* root, int level) {
    if (root == NULL)
        return;

    if (level == 1) {
        cout << "(" << root->val << ")";
    }
    treeLevelPrint(root->left, level-1);
    treeLevelPrint(root->right, level-1);
}

void treePrint(TreeNode* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        treeLevelPrint(root, i);
        cout<<endl;
    }
}



int main(void) {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(1);
    treePrint(root);
}