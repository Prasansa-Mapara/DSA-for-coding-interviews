class Solution {
public:
    bool isMatch(string s, string p) {
        int ns=s.size(), np=p.size();
        vector<vector<bool>> dp(ns+1, vector<bool>(np+1, 0));
        dp[0][0]=1;
        
        for(int j=2; j<=np; j++){
            if(p[j-1]=='*'){
                dp[0][j]=dp[0][j-2]; //not considering this star, since we've taken 0 elements from s;
            }
        }
        
        for(int i=1; i<=ns; i++){
            for(int j=1; j<=np; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){                    
                    //not taking star
                    dp[i][j]=dp[i][j-2];
                    //can take star only if it matches;
                    if(p[j-2]==s[i-1] || p[j-2]=='.'){
                        //taking single occurence of star;
                        dp[i][j]=dp[i-1][j-2] || dp[i][j];
                        //taking multiple occurences;
                        dp[i][j]=dp[i-1][j] || dp[i][j];
                    }
                }
            }
        }
        
        return dp[ns][np];
    }
};