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
int diff=0;
void differ(TreeNode*root,int miniVal,int maxVal){
    if(!root)return;
    diff=max(diff,max(abs(miniVal-root->val),abs(maxVal-root->val)));

    miniVal=min(miniVal,root->val);
    maxVal=max(maxVal,root->val);
    differ(root->right,miniVal,maxVal);
    differ(root->left,miniVal,maxVal);


}
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return 0;
        int miniVal=root->val;
        int maxVal=root->val;
        differ(root,miniVal,maxVal);
        return diff;
    }
};