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
#define ll long long

class Solution {
public:
    bool dfs(TreeNode *curr, ll mn, ll mx){
        if(!curr){
            return 1;
        }
        if(curr->val<=mn || curr->val>=mx){
            return 0;
        }
        return dfs(curr->right, curr->val, mx) && dfs(curr->left, mn, curr->val);
    }
    
    bool isValidBST(TreeNode* root) {
        //also dfs, just keep a range check;
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};