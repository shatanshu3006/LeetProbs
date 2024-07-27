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
typedef long long ll;
bool func(TreeNode*root,ll mini,ll maxi){
    if(!root)return true;
    if(root->val <=mini || root->val>=maxi)return false;
    return (func(root->left,mini,root->val) && (func(root->right,root->val,maxi)));
}
    bool isValidBST(TreeNode* root) {
        ll mini=LLONG_MIN,maxi=LLONG_MAX;
        return func(root,mini,maxi);
    }
};