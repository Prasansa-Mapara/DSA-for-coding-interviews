class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        if(n1+n2!=n3) return 0;
        if(n1==0 || n2==0){
            if(n1==0) return s2==s3;
            return s1==s3;
        }
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1));
        dp[0][0]=1;
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                if(!i && !j) dp[i][j]=1;
                else if(!i){
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1];
                }
                else if(!j){
                    dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i+j-1];
                }
                else{
                    dp[i][j]=(dp[i-1][j] && s1[i-1]==s3[i+j-1])||(dp[i][j-1] && s2[j-1]==s3[i+j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};