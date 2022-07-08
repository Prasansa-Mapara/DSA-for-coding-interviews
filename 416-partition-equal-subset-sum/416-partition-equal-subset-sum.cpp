class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(), sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2) return 0;
        int target=sum/2;
        vector<bool> dp(target+1, 0), curr=dp;
        dp[0]=1; if(nums[0]<=target) dp[nums[0]]=1;
        
        for(int i=1; i<n; i++){
            for(int k=0; k<=target; k++){
                curr[k]=0;
                if(k>=nums[i])curr[k]=dp[k-nums[i]];
                curr[k]=curr[k] | dp[k];
            }
            dp=curr;
        }
        return dp[target];
    }
};