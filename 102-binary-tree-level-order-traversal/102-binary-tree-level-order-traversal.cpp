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
    map<int, vector<int>> hash; 
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if(!root) return sol;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(q.size()){
            int curr=q.front().second;
            TreeNode *tmp=q.front().first;
            q.pop();
            hash[curr].push_back(tmp->val);
            
            if(tmp->left){
                q.push({tmp->left, curr+1});
            }
            if(tmp->right){
                q.push({tmp->right, curr+1});
            }
        }
        
        for(auto i=hash.begin(); i!=hash.end(); i++){
            sol.push_back(i->second);
        }
        return sol;
    }
};