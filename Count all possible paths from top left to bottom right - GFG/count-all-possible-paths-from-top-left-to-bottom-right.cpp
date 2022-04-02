// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        int mat[m][n];
        for(int i=0; i<m; i++){
            mat[i][0]=1;
        }
        for(int j=0; j<n; j++){
            mat[0][j]=1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                mat[i][j]=(mat[i-1][j]%mod+mat[i][j-1]%mod)%mod;
            }
        }
        return mat[m-1][n-1]%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends