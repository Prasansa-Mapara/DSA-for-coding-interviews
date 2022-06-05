// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int lo=1, hi=m;
	    while(lo<=hi){
	        int mid=lo+(hi-lo)/2;
	        long long int x=1;
	        //x^n==m
	        for(int i=1; i<=n; i++){
	            x*=mid;
	            if(x>m){
	                break;
	            }
	        }
	        if(x==m){
	            return mid;
	        }
	        else if(x>m){
	            hi=mid-1;
	        }
	        else{
	            lo=mid+1;
	        }
	    }
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends