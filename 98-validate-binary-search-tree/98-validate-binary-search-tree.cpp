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
    bool sol=1;
    
    void dfs(TreeNode *curr, ll mn, ll mx){
        if(!curr){
            return;
        }
        if(curr->val>mn && curr->val<mx){
            dfs(curr->right, curr->val, mx);
            dfs(curr->left, mn, curr->val);
        }
        else{
            sol=0;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        //also dfs, just keep a range check;
        ll mn=INT_MIN, mx=INT_MAX;
        mn--; mx++;
        dfs(root, mn, mx);
        return sol;
    }
};