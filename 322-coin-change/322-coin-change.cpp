class Solution {
public:
    int coinChange(vector<int>& cns, int amt) {
        int n=cns.size();
        vector<int> dp(amt+1, amt+1);
        dp[0]=0; 
        sort(cns.begin(), cns.end());
        for(int i=1; i<=amt; i++){
            for(int j=0; j<n; j++){
                if(cns[j]>i) break;
                dp[i]=min(dp[i], 1+dp[i-cns[j]]);
            }
        }
        return dp[amt]==amt+1?-1:dp[amt];
    }
};