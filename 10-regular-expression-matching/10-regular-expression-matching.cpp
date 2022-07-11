class Solution {
public:
    bool isMatch(string s, string p) {
        int ns=s.size(), np=p.size();
        vector<vector<bool>> dp(np+1, vector<bool>(ns+1, 0));
        dp[0][0]=1;
        
        for(int i=2; i<=np; i++){
            if(p[i-1]=='*'){
                dp[i][0]=dp[i-2][0];
            }
        }
        
        for(int i=1; i<=np; i++){
            for(int j=1; j<=ns; j++){
                if(p[i-1]==s[j-1] || p[i-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    dp[i][j]=dp[i-2][j];
                    if(p[i-2]=='.' || p[i-2]==s[j-1]){
                        dp[i][j]=dp[i][j-1] || dp[i][j];
                    }
                }
            }
        }
        
        return dp[np][ns];
    }
};