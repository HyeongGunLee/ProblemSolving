#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void findSum(TreeNode* root, int sum, vector<int>& path, int level) {
    if (root == NULL)
        return;

    path[level] = root->data;
    int temp;
    for (int i = level; i >= 0; i--) {
        temp += path[i];
        if (temp == sum)
            printPath(path, i, level);
    }

    findSum(root->left, sum, path, level+1);
    findSum(root->right, sum, path, level+1);

    path[level] = -1234;

}



void findSum(TreeNode* root, int sum) {
    int depth = depth(root);
    vector<int> path;
    findSum(root, sum, path, 0);
}