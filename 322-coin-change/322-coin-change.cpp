class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i][j]=min(dp[i][j], 1+dp[i][j-coins[i]]);
        int n=coins.size();
        //since we've an infinite reserve of coins, there's no reason of 
        //keeping track about which coin i'm on;
        
        sort(coins.begin(), coins.end());
        
        vector<int> dp(amount+1, amount+1);
        dp[0]=0; //to make amount 0, i need 0 coins;
        
        for(int i=1; i<=amount; i++){ 
            for(int j=0; j<n; j++){ //ith amount using jth coin;
                if(coins[j]>i) break;
                dp[i]=min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        
        return dp[amount]>amount?-1: dp[amount];
    }
};