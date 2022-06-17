class Solution {
public:
    void dfs(vector<vector<int>> &mat, vector<vector<int>> &ocean, int i, int j){
        if(ocean[i][j]) return;
        int r=mat.size(), c=mat[0].size();
        ocean[i][j]=1; //we've set the condition such that it'll always be feasible for this cell to visit the ocean;
        
        if(i+1<r && mat[i+1][j]>=mat[i][j]){ //water can flow from i+1th cell to ith cell;
            dfs(mat, ocean, i+1, j); 
        }
        if(i-1>=0 && mat[i-1][j]>=mat[i][j]){
            dfs(mat, ocean, i-1, j);
        }
        if(j+1<c && mat[i][j+1]>=mat[i][j]){
            dfs(mat, ocean, i, j+1);
        }
        if(j-1>=0 && mat[i][j-1]>=mat[i][j]){
            dfs(mat, ocean, i, j-1);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>> pac(r, vector<int>(c, 0)), atl=pac;
        //flows through pac if i==0 or j==0;
        //flows through atl if i==(r-1) or j==(c-1);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(i==0 || j==0){
                    dfs(mat, pac, i, j);
                }
                if(i==r-1 || j==c-1){
                    dfs(mat, atl, i, j);
                }
            }
        }
        vector<vector<int>> sol;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(atl[i][j] && pac[i][j]){
                    sol.push_back({i, j});
                }
            }
        }
        return sol;
    }
};