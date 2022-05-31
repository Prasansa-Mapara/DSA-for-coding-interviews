class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        //dp[amt]=min(dp[amt], 1+dp[amt-cns[i]]);
        //so we need to follow bottom-up approach;
        //initially we'll fill up the dp table with max value, which will be amt+1 in this case
        //as we will never need more than amt number of coins to make up amt;
        //we also know dp[0]=0;
        
        vector<int> dp(amt+1, amt+1);
        dp[0]=0;
        sort(coins.begin(), coins.end());
        for(int i=1; i<=amt; i++){
            for(auto currC: coins){
                if(currC<=i){ //because the amt is i, so coin will have to be less than or equal to i;
                    dp[i]=min(dp[i], 1+dp[i-currC]);
                }
                else{
                    break; //cuz all other coins will be greater than i, as coins array is sorted;
                }
            }
        }
        return dp[amt]==(amt+1)?-1:dp[amt];
    }
};