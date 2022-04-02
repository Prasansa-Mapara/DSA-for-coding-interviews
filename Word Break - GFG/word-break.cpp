// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> hash;
        int sz=0;
        for(auto s: B){
            hash.insert(s);
            sz=max(sz, (int)s.size());
        } 
        int n=A.size();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=i-1; j>=0; j--){
                int l=i-j;
                if(l>sz) break;
                if(dp[j]){
                    string s=A.substr(j, l);
                    if(hash.find(s)!=hash.end()){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends