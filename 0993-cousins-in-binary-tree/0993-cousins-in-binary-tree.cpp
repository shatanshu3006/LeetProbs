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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            bool f1=false,f2=false;
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                q.pop();

                //if values found
                if(temp->val==x)f1=true;
                if(temp->val==y)f2=true;

                //check if parent is same
                if(temp->left && temp->right){
                    if((temp->left->val==x && temp->right->val==y) || (temp->left->val==y && temp->right->val==x)){
                        return false;
                    }
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(f1==true && f2==true){
                return true;
            }
            else{
                return false;
            }
        }
    }
};