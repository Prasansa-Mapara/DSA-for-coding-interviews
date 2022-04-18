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
    vector<TreeNode*> sol;
    unordered_map<string, int> hash;
public:
    //i'll do postorder DFS to get the perfect structure of the subtree;
    string solve(TreeNode *curr){
        if(!curr) return "*";
        string l=solve(curr->left);
        string r=solve(curr->right);
        string tmp=to_string(curr->val)+"*"+l+"*"+r; //will have to do this, cuz in case of (1,11) and (11,1),
        //if we don't separate them, it will seem to be the same(111, 111);
        if(hash[tmp]==1){ //we have to return root node of only one subtree in case of >1 duplicates;
            sol.push_back(curr);
        }
        hash[tmp]++;
        return tmp;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        //here we have to maintain a string, and keep storing that string in a map, then check for repetition;
        if(!root) return sol;
        solve(root);
        
        return sol;
    }
};