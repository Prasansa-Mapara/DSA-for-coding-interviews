class TrieNode{
    public:
    TrieNode* children[26];
    string saz;
    
    TrieNode(){
        saz="";
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};

class Solution {
public:
    vector<string> sol;
    
    TrieNode* buildTrie(vector<string> &words){
        TrieNode *root=new TrieNode();
        for(auto s:words){
            TrieNode *curr=root;
            for(auto c:s){
                if(!curr->children[c-'a']) curr->children[c-'a']=new TrieNode();
                curr=curr->children[c-'a'];
            }
            curr->saz=s;
        }
    return root;
}
    
    void dfs(vector<vector<char>> &mat, int i, int j, TrieNode *curr){
        int r=mat.size(), c=mat[0].size();
        if(i<0 || i>=r || j<0 || j>=c || mat[i][j]=='#'){
            return;
        }
        char ch=mat[i][j];
        if(!curr->children[ch-'a']) return;
        curr=curr->children[ch-'a'];
        if(curr->saz.size()>0){
            sol.push_back(curr->saz);
            curr->saz="";
        }
        mat[i][j]='#';
        dfs(mat, i+1, j, curr);
        dfs(mat, i-1, j, curr);
        dfs(mat, i, j+1, curr);
        dfs(mat, i, j-1, curr);
        mat[i][j]=ch;
    }
    
    vector<string> findWords(vector<vector<char>>& mat, vector<string>& words) {
        TrieNode *root=buildTrie(words);
        int r=mat.size(), c=mat[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                dfs(mat, i, j, root);
            }
        }
        return sol;
    }
};