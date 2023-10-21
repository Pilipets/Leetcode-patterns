// In-Order Tree traversal - left, root, right
// https://leetcode.com/problems/binary-tree-inorder-traversal/
//
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    stack<TreeNode*> s;

    TreeNode* curr = root;
    while(!s.empty() || curr)
    {
        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top();
        s.pop();

        // process node here
        inorder.push_back(curr->val);
        
        curr = curr->right;
    }
    return inorder;
}


// Pre-Order Tree traversal - root, left, right
// https://leetcode.com/problems/binary-tree-preorder-traversal/
//
vector<int> preorderTraversal(TreeNode* root)
{
    if (root == NULL)
        return preorder;

    vector<int> preorder;
    stack<TreeNode*> stack{{root}};

    while(!stack.empty())
    {
        TreeNode* curr = stack.top();
        stack.pop();

        preorder.push_back(curr->val);

        // The right child is pushed before the left child to make sure that the left subtree is processed first.
        if (curr->right != NULL)
            stack.push(curr->right);
        if (curr->left != NULL)
            stack.push(curr->left);
    }
    return preorder;
}