class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        //dp[i][j]+=min(dp[i-1][j], dp[i-1][j-1]);
        int r=tri.size();
        vector<vector<int>> dp=tri;
        for(int i=1; i<r; i++){
            int c=tri[i].size();
            for(int j=0; j<c; j++){
                if(j==0){
                    dp[i][j]+=dp[i-1][j];
                }
                else if(j==c-1){
                    dp[i][j]+=dp[i-1][j-1];
                }
                else{
                    dp[i][j]+=min(dp[i-1][j], dp[i-1][j-1]);
                }
            }
        } 
        
        return *min_element(dp[r-1].begin(), dp[r-1].end());
    }
};