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
    //we'll need heights to check if balanced;
    //we need to check if each and every subtree is balanced;
    //so while checking heights, if unbalanced, then we'll just return -1;
    //as height can never be -1, this won't be an issue;
    
    int solve(TreeNode *curr){
        if(!curr) return 0;
        int l=solve(curr->left);
        if(l==-1){ //if left subtree is unbalanced, then just return -1;
            return -1;
        }
        int r=solve(curr->right);
        if(r==-1 || abs(r-l)>1){ //if right subtree is unbalanced or current is unbalanced;
            return -1;
        }
        //everything's balanced, so return height;
        return 1+max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        return (solve(root)==-1)?0:1;
    }
};