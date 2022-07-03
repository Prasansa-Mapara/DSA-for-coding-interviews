class Solution {
public:
    int coinChange(vector<int>& cns, int amt) {
        int n=cns.size();
        vector<int> dp(amt+1, INT_MAX);
        dp[0]=0; 
        sort(cns.begin(), cns.end());
        for(int i=1; i<=amt; i++){
            for(int j=0; j<n; j++){
                if(cns[j]>i) break;
                if(dp[i-cns[j]]!=INT_MAX)dp[i]=min(dp[i], 1+dp[i-cns[j]]);
            }
        }
        return dp[amt]==INT_MAX?-1:dp[amt];
    }
};