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
    int curr=0;
    
    TreeNode *createTree(vector<int>& pre, vector<int>& in, int st, int ed){
        if(st>ed) return NULL;
        TreeNode *root=new TreeNode(pre[curr]);
        int ind=st;
        while(ind<ed && in[ind]!=pre[curr]){
            ind++;
        }
        curr++;
        root->left=createTree(pre, in, st, ind-1);
        root->right=createTree(pre, in, ind+1, ed);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        int st=0, ed=n-1;
        return createTree(pre, in, st, ed);
    }
};