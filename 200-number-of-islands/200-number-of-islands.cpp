class Solution {
public:
    void dfs(vector<vector<char>> &mat, int i, int j){
        int r=mat.size(), c=mat[0].size();
        if(i<0 || j<0 || i>=r || j>=c || mat[i][j]=='0'){
            return;
        }
        mat[i][j]='0'; //marking it visited;
        dfs(mat, i+1, j); 
        dfs(mat, i-1, j);
        dfs(mat, i, j+1);
        dfs(mat, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& mat) {
        int islands=0, r=mat.size(), c=mat[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]=='1'){ //if its a land then run dfs;
                    dfs(mat, i, j);
                    islands++;
                }                
            }
        }
        return islands;
    }
};