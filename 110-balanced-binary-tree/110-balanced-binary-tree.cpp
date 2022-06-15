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
        int l=solve(root->left), r=solve(root->right);
        int x=abs(l-r);
        if(l!=-1 && r!=-1 && x<=1){
            return 1+max(l, r);
        }
        else{
            return -1;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return (solve(root)==-1)?false:true;
    }
};