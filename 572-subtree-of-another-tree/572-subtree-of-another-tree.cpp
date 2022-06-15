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
    bool isSame(TreeNode *x, TreeNode *y){
        if(!x && !y) return 1;
        else if(!x || !y) return 0;
        if(x->val == y->val){
            return isSame(x->left, y->left) && isSame(x->right, y->right);
        }
        return 0;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return 1;
        else if(!root || !subRoot) return 0;
        if(isSame(root, subRoot)) return 1;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};