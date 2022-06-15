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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //I can avoid using extra storage in hash;
        
        queue<TreeNode*> q;
        vector<vector<int>> sol;
        if(!root) return sol;
        q.push(root);
        
        while(q.size()){
            int n=q.size();
            vector<int> tmp;
            while(n--){ //this is one level;
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                tmp.push_back(curr->val);
            }
            sol.push_back(tmp);
        }
        
        return sol;
    }
};