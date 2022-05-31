// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int> dp(V+1, V+1);
	    dp[0]=0;
	    sort(coins, coins+M);
	    for(int i=1; i<=V; i++){
	        for(int j=0; j<M; j++){
	            int coin=coins[j];
	            if(i>=coin) dp[i]=min(dp[i], 1+dp[i-coin]);
	            else break;
	        }
	    }
	    return (dp[V]==(V+1))?(-1):dp[V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends