class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        if(s1==s2) return 0;
        if(n1<n2) return minDistance(s2, s1); //we want the first word to be greater;
    
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0)); //we want min ops;
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    //             delete          replace       insert
                    dp[i][j]=1+min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                }
            }
        }
        
        return dp[n1][n2];
    }
};