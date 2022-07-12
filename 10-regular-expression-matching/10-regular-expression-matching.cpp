class Solution {
public:
    bool isMatch(string s, string p) {
        int ns=s.size(), np=p.size();
        //* means p's preceding char can be repeated 0 or more times;
        vector<vector<bool>> dp(ns+1, vector<bool>(np+1, 0));
        dp[0][0]=1;
        for(int j=2; j<=np; j++){
            if(p[j-1]=='*'){
                dp[0][j]=dp[0][j-2];
            }
        }
        //if(np>=2 && p[1]=='*') dp[0][2]=1;
        for(int i=1; i<=ns; i++){
            for(int j=1; j<=np; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(s[i-1]==p[j-2] || p[j-2]=='.'){
                        dp[i][j]=dp[i-1][j]; //if i wish to take star in future;
                        dp[i][j]=dp[i-1][j-2] || dp[i][j]; //if i dont wish to take star in future;
                        dp[i][j]=dp[i][j-2] || dp[i][j]; //neither take the star, nor match with the string;
                    }
                    else{
                        dp[i][j]=dp[i][j-2]; //since doesn't match, can't take the star;
                    }
                }
            }
        }
        
        return dp[ns][np];
    }
};
