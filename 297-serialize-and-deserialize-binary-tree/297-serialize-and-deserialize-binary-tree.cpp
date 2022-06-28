/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int ind=0;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    
    TreeNode* solve(vector<string> &tmp){
        int n=tmp.size();
        if(ind==n) return NULL;
        if(tmp[ind]=="N"){
            ind++;
            return NULL;
        }
        TreeNode *root=new TreeNode(stoi(tmp[ind]));
        ind++;
        root->left=solve(tmp);
        root->right=solve(tmp); //dont need to increment ind before this, cuz it will already be incremented as this is a recursive function;
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        string tmp;
        for(auto i: data){
            if(i!=',') tmp.push_back(i);
            else{
                v.push_back(tmp);
                tmp="";
            }
        }
        return solve(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));