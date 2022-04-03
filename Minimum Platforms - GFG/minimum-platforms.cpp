// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
   
    int findPlatform(int arr[], int dep[], int n)
    /*
    At any given instance of time, same platform can not be used for both
    departure of a train and arrival of another train. In such cases, we 
    need different platforms.
    
    this is why, we have kept 0 for arrival, and 1 for departure, so in case of 
    same time, we will first consider arrival, then departure;
    
    ex: [[13,15],[1,13]]
    here ans is two, while for meeting rooms, ans is 1
    cuz its not possible to have two trains on the same platform at the same time;
    */
    {
    	vector<pair<int, int>>time;
    	for(int i=0; i<n; i++){
    	    time.push_back({arr[i], 0});
    	}
    	for(int i=0; i<n; i++){
    	    time.push_back({dep[i], 1});
    	}
    	sort(time.begin(), time.end());
    	int ans=0, k=0;
    	for(auto i: time){
    	    if(i.second==0) k++; //if arrival, increment the num of platforms
    	    else k--; //decrement
    	    ans=max(ans, k);
    	}
    	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends