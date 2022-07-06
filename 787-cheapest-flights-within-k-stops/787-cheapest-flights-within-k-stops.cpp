class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //it is a weighted graph;
        //since weight's the cost, it will never be negative;
        //there's a single source;
        //we can use dijkstra, and keep track of k;
        //or we can use dp(bellman ford), and it will relax at most k times;
        
        vector<vector<int>> dp(k+1, vector<int>(n, INT_MAX)); //dp[i][j] is cost needed to reach j in at most i iterations;
        //for all iterations, the price to reach the source node is 0;
        for(int i=0; i<=k; i++){
            dp[i][src]=0;
        }
        for(int i=0; i<=k; i++){
            for(auto f: flights){
                int u=f[0], v=f[1], cst=f[2];
                if(i==0){
                    if(u==src){
                        dp[i][v]=cst;
                    }
                }
                else if(dp[i-1][u]!=INT_MAX) dp[i][v]=min(dp[i][v], dp[i-1][u]+cst);
            }
        }
        
        return dp[k][dst]==INT_MAX?-1: dp[k][dst]; 
    }
};