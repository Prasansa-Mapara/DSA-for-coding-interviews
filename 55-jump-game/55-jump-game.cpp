class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector<bool> dp(n, 0);
        dp[n-1]=1;
        for(int i=n-2; i>=0; i--){
            if(dp[i]) continue;
            int x=nums[i];
            for(int j=0; j<=x; j++){
                if(i+j<n) dp[i]=dp[i]||dp[i+j];
                else break;
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};