// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxDigit(int l, int r)  {
        
        int arr[r+1]={0};
        
        // sieve creation
        
        for(int i=2;i<=r;i++){
            if(arr[i]==0){
                for(int j=i*i;j<=r;j+=i){
                    arr[j]=1;
                }
            }
        }
        
        // creation of digit array
        
        int digit[10]={0};
        bool flag=false;
        for(int i=l;i<=r;i++){
            if(arr[i]==0){
                flag=true;
                int num=i;
                
                while(num){
                    int rem=num%10;
                    digit[rem]++;
                    num=num/10;
                }
            }
        }
        
        // if the no prime numbers between [l,r]
        if(flag==false){
            return -1;
        }
        
        // finding the max occuring digit
        int mx=INT_MIN;
           int ans;
        for(int i=0;i<10;i++){
            
            if(digit[i]>=mx){
                mx=digit[i];
                ans=i;
            }
        }
        
     
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout<<ob.maxDigit(L,R)<<endl;
    }
    return 0;
}
  // } Driver Code Ends