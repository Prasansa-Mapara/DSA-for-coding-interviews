// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //max ops is n;
        if(n<=2) return n;
        
        vector<int> dp(n+1, INT_MAX);
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=2; i<=n; i++){
            if(i+1<=n)dp[i+1]=min(dp[i+1], dp[i]+1);
            if(2*i<=n)dp[2*i]=min(dp[2*i], dp[i]+1);
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends