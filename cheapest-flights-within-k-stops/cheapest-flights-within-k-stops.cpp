class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //it is a weighted graph;
        //since weight's the cost, it will never be negative;
        //there's a single source;
        //we can use dijkstra, and keep track of k;
        //or we can use dp(bellman ford), and it will relax at most k times;
        
        vector<vector<int>> dp(k+1, vector<int> (n, INT_MAX));
        for(int i=0; i<=k; i++){
            dp[i][src]=0; //cost to reach the src node in at most i stops;
        }
        for(int i=0; i<=k; i++){
            for(auto f: flights){ //in bellman ford, or dp, we traverse through all the edges;
                int u=f[0], v=f[1], cst=f[2];
                if(i==0){ //at most 0 stops, so we can only reach v if u==src;
                    if(u==src){
                        dp[i][v]=cst;
                    }
                }
                else{
                    if(dp[i-1][u]!=INT_MAX)dp[i][v]=min(dp[i-1][u]+cst, dp[i][v]); //if its possible to reach 
                    //the prev vertex with at most i-1 stops, then reaching the current vertex;
                }
            }
        }
        
        return dp[k][dst]==INT_MAX?-1: dp[k][dst];
    }
};