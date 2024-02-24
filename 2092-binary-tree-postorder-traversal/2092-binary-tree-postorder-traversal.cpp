/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> res;
        
        TreeNode *prev = nullptr;
        
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top(); s.pop();
            
            if (root->right == prev) {
                res.push_back(root->val);
                prev = root;
            } else {
                s.push(root);
                root = root->right;
            }
        }
        
        return res;
    }
};