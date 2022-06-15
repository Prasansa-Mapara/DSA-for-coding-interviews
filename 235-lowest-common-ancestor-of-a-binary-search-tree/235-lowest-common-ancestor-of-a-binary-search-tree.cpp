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
        //recursive takes O(n) space;
        //so doing it in O(1) space;
        
        while(root){
            int x=p->val, y=q->val, k=root->val;
            if(x==k || y==k){
                return root;
            }
            else if(x<k && y<k){ //both on left side;
                root=root->left;
            }
            else if(x>k && y>k){ //both on right side;
                root=root->right;
            }
            else{ //both on opposite sides;
                return root;
            }
        }
        
        return root;
    }
};