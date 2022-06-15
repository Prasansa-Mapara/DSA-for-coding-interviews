/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int x=p->val, y=q->val, k=root->val;
        if(x==k || y==k) return root;
        if(x<k && y<k){ //both are on left side;
            return lowestCommonAncestor(root->left, p, q);
        }
        else if((x<k && y>k) || (x>k && y<k)){ //both are on opp. side;
            return root;
        }
        else{
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};