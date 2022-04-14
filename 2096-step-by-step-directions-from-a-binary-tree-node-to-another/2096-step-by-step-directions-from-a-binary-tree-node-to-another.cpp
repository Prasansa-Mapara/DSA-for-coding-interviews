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
    //here notice that we will have to take the path from root to destination, if start node is at the left end of root;
    //else if start node is root, or at the right end of root, or both start and destination nodes are at the same ends, then
    //go from start to desti, i.e. remove the prefix (take root to start, and root to desti, now remove common prefix)
    //then replace root->start path with U and append root->desti path to it;
public:
    void getPath(string &s, TreeNode *curr, int &k, bool &found){
        if(curr->val==k){
            found=1; //now that i have found the path, i'll return and i don't wanna go into any other condition hence
            //i've kept && !found;
            return;
        }
        if(curr->left && !found){
            s+="L";
            getPath(s, curr->left, k, found);
        }
        if(curr->right && !found){
            s+="R";
            getPath(s, curr->right, k, found);
        }
        if(!found) s.pop_back(); //go a step back 
        return;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string st, dt;
        bool found=0;
        getPath(st, root, startValue, found);
        found=0;
        getPath(dt, root, destValue, found);
        int i=0, j=0, n1=st.size(), n2=dt.size();
        while(i<n1 && j<n2){
            if(st[i]==dt[j]){
                i++; j++;
            }
            else break;
        }
        st=st.substr(i);
        dt=dt.substr(j);
        for(i=0; i<st.size(); i++){ //replace st with U's
            st[i]='U';
        }
        st+=dt; //append dt to st;
        return st;
    }
};