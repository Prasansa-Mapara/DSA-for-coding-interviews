// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int n, int d) {
	    string ans=to_string(n/d);
	    if(!(n%d)){
	        return ans;
	    }
	    ans+=".";
	    int rem=n%d;
	    string res="";
	    unordered_map<int, int> um;
	    while(rem && um.find(rem)==um.end()){
	        //if reminder is 0, then end; 
	        //if reminder repeats, then also end;
	        um[rem]=res.size();
	        rem*=10;
	        int frac=rem/d;
	        res+=to_string(frac);
	        rem=rem%d;
	    }
	    if(um.find(rem)!=um.end()){ //recurring;
	        
	        int x=um[rem];
	        ans+=res.substr(0, x);
	        ans+="("+res.substr(x)+")";
	    }
	    else if(!rem){
	        ans+=res;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends