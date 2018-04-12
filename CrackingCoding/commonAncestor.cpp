

bool covers(TreeNode* root, TreeNode* p) {
    if (root == NULL) return false;
    if (root == p) return true;
    return covers(root->left, p) || covers(root->right, p);
}


TreeNode* commonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
    bool on_left_p = covers(root->left, p);
    bool on_left_q = covers(root->left, q);

    if (on_left_p != on_left_q)
        return root;

    TreeNode* childside = on_left_p ? root->left : loot->right;

    return commonAncestorHelper(childside, p, q);
}

TreeNode commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!covers(root, p) || !covers(root, q))
        return false;

    return commonAncestorHelper(root, p, q);
}