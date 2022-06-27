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
    int cnt=0;
    
    void dfs(TreeNode *root, int curr){
        if(!root) return;
        if(root->val>=curr){
            cnt++;
            curr=root->val;
        }
        dfs(root->right, curr);
        dfs(root->left, curr);
    }
    
    int goodNodes(TreeNode* root) {
        //dfs along with the current value;
        dfs(root, INT_MIN);
        return cnt;
    }
};