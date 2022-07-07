class Solution {
public:
    int solve(vector<int> v){
        int n=v.size();
        vector<int> dp(n+2, 0);
        for(int i=0; i<n; i++){
            dp[i+2]=max(v[i]+dp[i], dp[i+1]);
        }
        return dp[n+1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(solve({nums.begin(), nums.end()-1}), solve({nums.begin()+1, nums.end()}));
    }
};