// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> a1, a2;
        for(int i=0; i<n; i++){
            a1.push_back(arr1[i]);
        }
        for(int i=0; i<m; i++){
            a2.push_back(arr2[i]);
        }
        int lo=min(a1[0], a2[0]), hi=max(a1[n-1], a2[m-1]);
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int cnt=upper_bound(a1.begin(), a1.end(), mid)-a1.begin()+
                    upper_bound(a2.begin(), a2.end(), mid)-a2.begin();
            if(cnt<k){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return hi;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends