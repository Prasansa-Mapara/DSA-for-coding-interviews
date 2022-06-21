class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); //one for buy, another for sale;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j==0){ //if buying or doing nothing;
                    dp[i][j]=max(dp[i+1][1]-prices[i], dp[i+1][j]);
                }
                else{ //if selling or doing nothing;
                    dp[i][j]=max(dp[i+2][0]+prices[i], dp[i+1][j]);
                }
            }
        }
        return dp[0][0]; //because we are set to buy on the first day;
    }
};