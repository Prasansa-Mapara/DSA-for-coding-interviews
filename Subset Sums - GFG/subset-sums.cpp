// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    vector<int> sol;
    
    void solve(int ind, vector<int> &arr, int currSum){
        int n=arr.size();
        if(ind==n){
            sol.push_back(currSum);
            return;
        }
        solve(ind+1, arr, currSum);
        solve(ind+1, arr, currSum+arr[ind]);
    }
    
    vector<int> subsetSums(vector<int> arr, int N){
        solve(0, arr, 0);
        return sol;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends