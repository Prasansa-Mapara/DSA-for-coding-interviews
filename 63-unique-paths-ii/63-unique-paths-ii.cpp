class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>> dp=mat;
        if(mat[0][0] || mat[r-1][c-1]) return 0;
        
        dp[0][0]=1;
        for(int j=1; j<c; j++){
            dp[0][j]=mat[0][j]?0: dp[0][j-1];
        }
        for(int i=1; i<r; i++){
            dp[i][0]=mat[i][0]?0: dp[i-1][0];
        }
        
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                dp[i][j]=mat[i][j]?0: dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[r-1][c-1];
    }
};