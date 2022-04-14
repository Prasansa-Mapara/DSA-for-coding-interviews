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
    vector<vector<int>> sol;
public:
    int findHeight(TreeNode *curr){
        if(!curr) return -1;
        int curH=1+max(findHeight(curr->left), findHeight(curr->right));
        if(sol.size()<=curH) sol.push_back({});
        sol[curH].push_back(curr->val);
        return curH;
    }
    //notice that all the nodes at the same height are in one vector, and the traversal is DFS, so that is
    //essentially what we are doing, calculate height of the curr node and push_back its value at that height
    //in sol; 
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root) return sol;
        int curH=1+max(findHeight(root->left), findHeight(root->right));
        if(sol.size()<=curH) sol.push_back({});
        sol[curH].push_back(root->val);
        return sol;
    }
};