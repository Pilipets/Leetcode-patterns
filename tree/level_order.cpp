// Level-order Tree Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/
//
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<TreeNode*> q({root});
    while (!q.empty())
    {
        vector<int> cur;
        cur.reserve(q.size());
        for (auto s = q.size(); s; --s)
        {
            root = q.front(); q.pop();
            cur.push_back(root->val);
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }
        res.push_back(std::move(cur));
    }
    return res;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if(!root) return res;
    
    vector<Node*> pre_level({root});
    
    while(!pre_level.empty())
    {
        vector<Node*> new_level;
        vector<int> res_level;

        for(Node* temp: pre_level)
        {
            res_level.push_back(temp->val);
            if(temp->left) new_level.push_back(temp->left);
            if(temp->right) new_level.push_back(temp->right);
        }
        res.push_back(std::move(res_level));
        swap(pre_level, new_level);
    }
    return res;
}