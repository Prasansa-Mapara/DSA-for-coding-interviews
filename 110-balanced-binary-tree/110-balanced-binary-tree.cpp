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
    int solve(TreeNode *root){
        if(!root){
            return 0;
        }
        int l=solve(root->left);
        if(l==-1) return -1;
        int r=solve(root->right);
        if(r==-1) return -1;
        int x=abs(l-r);
        if(x>1) return -1;
        return 1+max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return (solve(root)==-1)?false:true;
    }
};