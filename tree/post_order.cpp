// Post-Order Tree traversal - left, right, root
// 
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/


// Similar to Inorder using 1 Stack. The difference is we keep track of the previously printed node in pre.
// And we only print a node if its right child is null or equal to pre
//
vector<int> postOrderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    TreeNode* pre = nullptr;
    stack<TreeNode*> st;
    while (!st.empty() || root) {
        if (root) {
            st.push(root);
            root = root->left;
        }
        else {
            root = st.top();
            if (root->right == nullptr || root->right == pre) {
                res.push_back(root->val);
                st.pop();
                pre = root;
                root = nullptr;
            }
            else {
                root = root->right;
            }
        }
    }

    return res;
}


// root --> right --> left . Than reverse it:
//
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    if(root == NULL) return result;

    stack<TreeNode*> stk{{root}};
    while(!stk.empty())
    {
        auto cur = stk.top();
        result.push_back(cur->val);
        stk.pop();

        if(cur->left) stk.push(cur->left);
        if(cur->right) stk.push(cur->right);
    }

    reverse(result.begin(), result.end());
    return result;
}


// post-order push twice
//
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ret;
    if(!root) return ret;

    stack<TreeNode*> st{{root, root}};
    TreeNode *cur;
    while(!st.empty()){
        cur = st.top();
        st.pop();

        if(!st.empty()&&st.top() == cur){
            if(cur->right) {
                st.push(cur->right);
                st.push(cur->right);
            }
            if(cur->left){
                st.push(cur->left);
                st.push(cur->left);
            }
        }
        else
            ret.push_back(cur->val);
    }
    return ret;
}