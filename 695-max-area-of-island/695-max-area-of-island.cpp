class Solution {
public:
    int dfs(vector<vector<int>> &mat, int i, int j){
        int r=mat.size(), c=mat[0].size();
        if(i<0 || j<0 || i>=r || j>=c || !mat[i][j]){
            return 0;
        }
        mat[i][j]=0;
        return 1+dfs(mat, i+1, j)+dfs(mat, i-1, j)+dfs(mat, i, j+1)+dfs(mat, i, j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& mat) {
        //here we want addition of all 1s;
        int area=0, r=mat.size(), c=mat[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]){
                    area=max(area, dfs(mat, i, j));
                }
            }
        }
        return area;
    }
};