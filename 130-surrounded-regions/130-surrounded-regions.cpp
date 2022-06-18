class Solution {
public:
    void dfs(vector<vector<char>> &mat, int i, int j){
        int r=mat.size(), c=mat[0].size();
        if(i<0 || j<0 || i>=r || j>=c || mat[i][j]!='O') return;
        mat[i][j]='F'; //mark it visited;
        dfs(mat, i+1, j); dfs(mat, i-1, j);
        dfs(mat, i, j+1); dfs(mat, i, j-1);
    }
    
    void solve(vector<vector<char>>& mat) {
        //basically we need corner vaale connected O's;
        //then except for those, all will be converted;
        int r=mat.size(), c=mat[0].size();
        for(int i=0; i<r; i++){
            if(mat[i][0]=='O'){
                dfs(mat, i, 0);
            }
            if(mat[i][c-1]=='O'){
                dfs(mat, i, c-1);
            }
        }
        for(int j=0; j<c; j++){
            if(mat[0][j]=='O'){
                dfs(mat, 0, j);
            }
            if(mat[r-1][j]=='O'){
                dfs(mat, r-1, j);
            }
        }
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]=='O') mat[i][j]='X';
                else if(mat[i][j]=='F') mat[i][j]='O';
            }
        }
        return;
    }
};