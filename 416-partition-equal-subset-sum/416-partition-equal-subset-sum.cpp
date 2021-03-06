class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(), sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2) return 0;
        int target=sum/2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        dp[0][0]=1;
        if(nums[0]<=target) dp[0][nums[0]]=1;
        for(int i=1; i<n; i++){
            for(int k=0; k<=target; k++){
                if(k>=nums[i])dp[i][k]= dp[i][k] | dp[i-1][k-nums[i]];
                dp[i][k]= dp[i][k] | dp[i-1][k];
            }
        }
        return dp[n-1][target];
    }
};