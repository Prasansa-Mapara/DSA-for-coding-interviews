class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        dp[1]=(s[0]=='0'?0:1);
        for(int i=1; i<n; i++){
            if(s[i]!='0'){
                dp[i+1]=dp[i];
            }
            int x=stoi(s.substr(i-1, 2));
            if(x>=10 && x<=26){
                dp[i+1]+=dp[i-1];
            }
        }
        return dp[n];
    }
};