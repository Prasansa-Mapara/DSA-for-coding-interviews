class Solution {
public:
    vector<vector<int>> dir={{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    int dfs(int x, int y, vector<vector<int>> &dp, vector<vector<int>> &mat){
        int r=mat.size(), c=mat[0].size();
        if(dp[x][y]) return dp[x][y];
        
        int sol=1;
        
        for(int k=0; k<4; k++){
            int i=x+dir[k][0], j=y+dir[k][1];
            if(i>=0 && i<r && j>=0 && j<c && mat[i][j]>mat[x][y]){ //we can go to i,j from x,y;
                sol=max(sol, 1+dfs(i, j, dp, mat));
            }
        }
        
        dp[x][y]=sol;
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        //this is dp + dfs;
        //we'll have to dfs but along with that, we can also store the result along the way;
        int r=mat.size(), c=mat[0].size(), sol=0;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!dp[i][j]){ //if we dont yet have the result;
                    dfs(i, j, dp, mat);
                }
                sol=max(sol, dp[i][j]);
            }
        }
        
        return sol;
    }
};