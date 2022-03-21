class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP=1e4, profit=0, n=prices.size();
        for(int i=0; i<n; i++){
            minP=min(minP, prices[i]);
            int curr=prices[i]-minP;
            if(curr>profit){
                profit=curr;
            }
        }
        return profit;
    }
};