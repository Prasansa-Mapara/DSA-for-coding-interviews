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
    vector<int> sol;
    
    void dfs(TreeNode *root, int lev){
        if(!root) return;
        if(lev==sol.size()){
            sol.push_back(root->val);
        }
        dfs(root->right, lev+1);
        dfs(root->left, lev+1); //cuz we first wanna go right, obviously;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        //we basically doing traversal, where at each level, we just need one right-most node;
        //so keep track of levels too;
        //if(lev==sol.size()) then it's the node;
        dfs(root, 0);
        return sol;
    }
};