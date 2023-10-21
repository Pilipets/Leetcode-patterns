// Morris Tree Traversal
//
// https://en.wikipedia.org/wiki/Threaded_binary_tree
// https://www.geeksforgeeks.org/threaded-binary-tree/
// https://leetcode.com/problems/binary-tree-inorder-traversal/
//
// Algorithm based on Threaded Binary Tree:
// - Make all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists).
// - Enables to find parent node without explicit use of parent pointer
// - Nodes contain pointers to in-order predecessor and successor
// - Single threaded(right NULL -> inorder successor)
// - Double Threaded(left and right NULL -> inorder predecessor and inorder successor respectively.)
//
// Time complexity O(N), space O(1):
// - A n-node binary tree has n-1 edges. In a Morris traversal, one edge is visited at most 3 times.
// - 1st visit is for locating a node. 2nd visit is for looking for the predecessor of some node.
// - And 3rd/final is for restoring the right child of the predecessor to null.


// traverse and revert changes back
//
vector<int> morisTraversalRecover(TreeNode* root)
{
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr)
    {
        if(curr->left)
        {
            TreeNode* pre = curr->left;
            while(pre->right != nullptr && pre->right != curr)
                pre = pre->right;

            // Make current as the right child of its inorder predecessor
            if(pre->right == nullptr)
            {
                pre->right = curr;
                curr = curr->left;
            }
            // Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor
            else
            {
                pre->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
        else
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
    }
    return inorder;
}


// morris that modifies the tree
//
vector<int> morisTraversal(TreeNode* root)
{
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr)
    {
        if(curr->left)
        {
            TreeNode* pre = curr->left;
            while(pre->right)
                pre = pre->right;

            pre->right = curr;
            TreeNode* temp = curr;
            curr = curr->left;
            temp->left = nullptr;
        }
        else
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
    }
    return inorder;
}