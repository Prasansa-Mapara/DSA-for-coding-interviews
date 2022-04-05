class Solution {
public:
    void dfs(vector<vector<char>>& mat, int i, int j){
        int m=mat.size(), n=mat[0].size();
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }
        else if(mat[i][j]=='0') return;
        mat[i][j]='0';
        dfs(mat, i+1, j);
        dfs(mat, i-1, j);
        dfs(mat, i, j+1);
        dfs(mat, i, j-1);
        return;        
    }
    
    int numIslands(vector<vector<char>>& mat) {
        int m=mat.size(), n=mat[0].size(), island=0;
        //dfs, 4 directions;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]=='1'){
                    dfs(mat, i, j);
                    island++;
                }
            }
        }
        return island;
    }
};