/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int depth=0;
        if(root==NULL){
            return 0;
        }
        while(!q.empty()){
            int sz=q.size();
            depth++;
            for(int i=0;i<sz;i++){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                if(curr->left==NULL && curr->right==NULL){
                    return depth;
                }
            }
        }
        return depth;
    }
};