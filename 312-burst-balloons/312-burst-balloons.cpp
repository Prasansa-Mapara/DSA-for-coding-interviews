class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //if i pop the ith balloon last, it will be nums[i]*nums[l-1]*nums[r+1]+dp[l][i-1]+dp[i+1][r];
        //since, now, [l, i-1] is not connected to [i+1, r] as we popping i last;
        //so l's increasing, r's decreasing;
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n=nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int l=n-1; l>0; l--){
            for(int r=0; r<n-1; r++){
                for(int i=l; i<=r; i++){
                    int curCoin=nums[i]*nums[l-1]*nums[r+1];
                    curCoin+=dp[l][i-1]+dp[i+1][r]; //since these two aren't connected;
                    dp[l][r]=max(dp[l][r], curCoin);
                }
            }
        }
        
        return dp[1][n-2];
    }
};