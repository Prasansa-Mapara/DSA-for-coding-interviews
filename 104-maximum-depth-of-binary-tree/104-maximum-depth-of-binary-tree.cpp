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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int sol=0;
        while(st.size()){
            TreeNode *curr=st.top().first;
            int depp=st.top().second;
            st.pop();
            sol=max(sol, depp);
            if(curr->left){
                st.push({curr->left, depp+1});
            }
            if(curr->right){
                st.push({curr->right, depp+1});
            }
        }
        return sol;
    }
};