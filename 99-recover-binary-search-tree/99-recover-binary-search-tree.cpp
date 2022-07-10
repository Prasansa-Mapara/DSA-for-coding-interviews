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
    TreeNode *x=NULL, *y=NULL, *pred=NULL;
    
    void swap(TreeNode *a, TreeNode *b){
        int tmp=a->val;
        a->val=b->val;
        b->val=tmp;
    }
    
    void in(TreeNode *root){
        if(!root) return; 
        in(root->left);
        if(pred && root->val < pred->val){ //pred should be lower;
            y=root;
            if(!x) x=pred;
            else return;
        }
        pred=root;
        in(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        //we just need a sorted list;
        //in an inorder traversal, the next element of the array, has to be greater than the current element;
        //so i can keep a pred, if currNode<pred, then we know currNode needs to be swapped;
        
        in(root);
        swap(x, y);
        return;
    }
};