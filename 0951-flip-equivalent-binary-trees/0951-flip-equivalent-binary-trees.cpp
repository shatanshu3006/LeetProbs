class Solution {
public:
    void help(TreeNode* root, unordered_map<int, set<int>>&store)
    {
        queue<TreeNode*>q;
        if(root) 
        {
            store[root->val].insert(-1);
            q.push(root);
        }
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto node = q.front(); q.pop();
                if(node->left) 
                {
                    store[node->val].insert(node->left->val);
                    q.push(node->left);
                }
                if(node->right) 
                {
                    store[node->val].insert(node->right->val);
                    q.push(node->right);
                }
            }
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        unordered_map<int, set<int>>store1, store2;
        help(root1, store1);
        help(root2, store2);

        return store1 == store2;
    }
};