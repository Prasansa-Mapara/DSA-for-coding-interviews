class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        if(n1+n2!=n3) return 0;
        if(n1==0 || n2==0){
            if(!n1) return s2==s3;
            else return s1==s3;
        }
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, 0));
        //this is just like LCS;
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                if(!i && !j) dp[i][j]=1; //if we dont take any characters from both strings;
                else if(!i){ //if we dont take any char from first string;
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1]; //here its 1 indexing, hence j-1 for string;
                    //if we dont take any char from s1, then it should be if it matched previously for s2,
                    //then check if curr char's matching;
                }
                else if(!j){ //no chars from second string;
                    dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i+j-1];
                }
                else{ //we taking chars from both strings;
                    bool x=s1[i-1]==s3[i+j-1] && dp[i-1][j]; //curr char in s1's matching so check for previous;
                    bool y=s2[j-1]==s3[i+j-1] && dp[i][j-1];
                    dp[i][j]=x || y;
                }
            }
        }
        return dp[n1][n2];
    }
};