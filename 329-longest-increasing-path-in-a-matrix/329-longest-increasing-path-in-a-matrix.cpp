class Solution {
public:
    vector<vector<int>> dir={{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    int dfs(int x, int y, vector<vector<int>> &dp, vector<vector<int>> &mat) {
        int r=mat.size(), c=mat[0].size();
        if(dp[x][y]) return dp[x][y];
        
        int curr=1;
        
        for(int k=0; k<4; k++){
            int i=dir[k][0]+x, j=dir[k][1]+y;
            if(i>=0 && j>=0 && i<r && j<c && mat[i][j]>mat[x][y]){
                curr=max(curr, 1+dfs(i, j, dp, mat));
            }
        }
        dp[x][y]=curr;
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        int sol=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!dp[i][j]){
                    dfs(i, j, dp, mat);
                }
                sol=max(sol, dp[i][j]);
            }
        }
        return sol;
    }
};