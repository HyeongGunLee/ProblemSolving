#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(NULL), right(NULL) {}
};

int search(vector<int>& inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
}

TreeNode* buildTreeHelp(vector<int>& postorder, vector<int>& inorder, int start, int end, int* pIndex) {
    if (start > end)
        return NULL;

    TreeNode* root = new TreeNode(postorder[*pIndex]);
    (*pIndex)--;

    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    root->left = buildTreeHelp(postorder, inorder, start, inIndex-1, pIndex);
    root->right = buildTreeHelp(postorder, inorder, inIndex+1, end, pIndex);
    return root;
}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {

    int size = postorder.size();
    int pIndex = size-1;
    return buildTreeHelp(postorder, inorder, 0, size-1, &pIndex);
}

int main(void) {

}