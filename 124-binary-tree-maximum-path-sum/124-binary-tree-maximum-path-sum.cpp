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
    int sol=INT_MIN;
    
    int maxSum(TreeNode *root){
        if(!root){
            return 0;
        }
        int curr=root->val;
        int left=maxSum(root->left);
        int right=maxSum(root->right);
        int ret=max(curr, curr+max(left, right));
        sol=max(sol, max(curr+left+right, ret));
        return ret;
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return sol;
    }
};