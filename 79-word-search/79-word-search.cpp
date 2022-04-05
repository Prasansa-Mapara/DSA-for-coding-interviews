class Solution {
public:
    bool dfs(vector<vector<char>> &mat, int i, int j, int &curr, string &s){
        if(curr>=s.size()) return true;
        int r=mat.size(), c=mat[0].size();
        if(i<0 || i>=r || j<0 || j>=c) return false;
        else if(mat[i][j]!=s[curr]) return false;
        char x=mat[i][j];
        mat[i][j]='0';
        int k=curr+1;
        bool sol=dfs(mat, i, j+1, k, s) || dfs(mat, i+1, j, k, s) || dfs(mat, i, j-1, k, s) || dfs(mat, i-1, j, k, s);
        mat[i][j]=x;
        return sol;
    }
    
    bool exist(vector<vector<char>>& mat, string s) {
        int r=mat.size(), c=mat[0].size(), curr=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]==s[curr]){
                    if(dfs(mat, i, j, curr, s)) return true;
                }
            }
        }
        return false;
    }
};