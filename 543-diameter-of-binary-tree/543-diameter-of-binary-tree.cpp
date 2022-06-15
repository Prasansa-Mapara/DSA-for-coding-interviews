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
    int sol=0;
    
    int solve(TreeNode *root){
        if(!root) return 0;
        int left=solve(root->left), right=solve(root->right);
        sol=max(sol, left+right);
        return 1+max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return sol;
    }
};