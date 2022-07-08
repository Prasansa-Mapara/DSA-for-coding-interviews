class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        //dp[i][j]+=min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
        vector<vector<int>> dp=mat;
        for(int i=1; i<r; i++){
            for(int j=1; j<c-1; j++){
                dp[i][j]+=min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
            }
            if(1<c){
                dp[i][0]+=min(dp[i-1][0], dp[i-1][1]);
            }
            else{
                dp[i][0]+=dp[i-1][0];
            }
            if(c-2>=0){
                dp[i][c-1]+=min(dp[i-1][c-1], dp[i-1][c-2]);
            }
            else{
                dp[i][c-1]+=dp[i-1][c-1];
            }
        }
        
        return *min_element(dp[r-1].begin(), dp[r-1].end());
    }
};