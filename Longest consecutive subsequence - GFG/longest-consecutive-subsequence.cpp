// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int n=0;
        for(int i=0; i<N; i++){
            n=max(n, arr[i]);
        }
        vector<int> v(n+1, 0);
        for(int i=0; i<N; i++){
            v[arr[i]]=1;
        }
        int cnt=0, ans=1;
        for(int i=0; i<=n; i++){
            if(v[i]==1){
                cnt++;
            }
            else{
                cnt=0;
            }
            ans=max(ans, cnt);
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends