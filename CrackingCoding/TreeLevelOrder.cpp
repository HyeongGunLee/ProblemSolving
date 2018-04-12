int height(TreeNode* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);


        if (leftHeight > rightHeight)
        {
            return leftHeight+1;
        } else
        {
            return rightHeight + 1;
        }
    }
}

void printLevelOrder(TreeNode* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root,  i);
    }
}

void printGivenLevel(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        cout << root->val;
    } else {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}



void printLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
            q.push(node->right);
    }
}

void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> treeQ;

    treeQ.push(root);
    while (!treeQ.isempty()) {
        TreeNode* node = treeQ.top();
        treeQ.pop();

        cout << node->data << endl;

        if (node->left != NULL)
            treeQ.push(node->left);

        if (node->right != NULL)
            treeQ.push(node->right);
    }
}








void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;

    q.push(root);

    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;

        while (nodeCount > 0) {
            TreeNode* node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}





void printLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        cout << node->data << “ “;
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}
