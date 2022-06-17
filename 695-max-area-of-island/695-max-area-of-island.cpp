class Solution {
public:
    int dfs(vector<vector<int>> &mat, int i, int j){
        int r=mat.size(), c=mat[0].size();
        if(i<0 || j<0 || i>=r || j>=c || !mat[i][j]){
            return 0;
        }
        mat[i][j]=0;
        int x=dfs(mat, i+1, j), y=dfs(mat, i, j+1);
        int z=dfs(mat, i-1, j), w=dfs(mat, i, j-1);
        return 1+x+y+z+w;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size(), area=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]){ //if its a land then do dfs; 
                    area=max(area, dfs(mat, i, j));
                }
            }
        }
        return area;
    }
};