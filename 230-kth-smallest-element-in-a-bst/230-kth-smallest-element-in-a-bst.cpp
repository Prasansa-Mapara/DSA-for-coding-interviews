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
    vector<int> v;
    
    void dfs(TreeNode *curr){
        if(!curr) return;
        dfs(curr->left);
        v.push_back(curr->val);
        dfs(curr->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        //if extra space is allowed then i'll store elements in an array;
        dfs(root);
        return v[k-1];
    }
};