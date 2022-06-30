class Solution {
public:
    vector<vector<char>> mat;
    string s;
    
    bool dfs(int x, int y, int ind){
        int n=s.size(), r=mat.size(), c=mat[0].size();
        if(ind>=n) return 1;
        if(x<0 || y<0 || x>=r || y>=c || mat[x][y]=='#' || mat[x][y]!=s[ind]){
            return 0;
        }
        char ch=mat[x][y];
        //now we know it matches current character, so do dfs;
        mat[x][y]='#';
        bool ret= dfs(x+1, y, ind+1) || dfs(x-1, y, ind+1) || dfs(x, y+1, ind+1) || dfs(x, y-1, ind+1);
        mat[x][y]=ch;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        mat=board; 
        s=word;
        int r=mat.size(), c=mat[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(dfs(i, j, 0)){
                    return 1;
                }
            }
        }
        return 0;
    }
};