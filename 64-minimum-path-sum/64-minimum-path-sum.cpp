class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>> dp=mat;
        for(int j=1; j<c; j++){
            dp[0][j]+=dp[0][j-1];
        }
        for(int i=1; i<r; i++){
            dp[i][0]+=dp[i-1][0];
        }
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                dp[i][j]+=min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[r-1][c-1];
    }
};