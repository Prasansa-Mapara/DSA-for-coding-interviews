class Solution {
public:
    int change(int amt, vector<int>& coins) {
        vector<int> dp(amt+1, 0);
        dp[0]=1; //there's one way to kepe amt 0; don't choose any coin;
        int n=coins.size();
        for(int i=0; i<n; i++){ //if i use the ith coin, i'll be able to contribute for ith amt or the amt greater than that;
            for(int j=coins[i]; j<=amt; j++){ //j is the current amt;
                dp[j]+=dp[j-coins[i]];
            }
            
        }
        return dp[amt];
    }
};