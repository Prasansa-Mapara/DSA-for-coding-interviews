class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0]=1; dp[1]=1;
        for(int i=2; i<=n; i++){
            //here i can either reach from (i-1)th step or (i-2)th step;
            dp[i]+=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};