class Solution {
public:
    bool isMatch(string A, string B) {
        int r=B.length(), c=A.length();
        int cnt=0;
        for(int i=0; i<r; i++){
            if(B[i]!='*'){
                cnt++;
            }
        }
        if(cnt>c){  //first check wats obvious, if passes this, then go to next step
            return 0;
        }
        vector<vector<bool>> dp(r+1, vector<bool>(c+1, false)); //since it will be 0, 1
        //makes more sense declaring dp of bool as it will take up 4 times lesser space. 
        dp[0][0]=true; //if both string are null, they match
        
        for(int i=1; i<=r; i++){
            if(B[i-1]=='*'){
                dp[i][0]=dp[i-1][0]; //if its a star, then if prev string matched then 1
            }
        }
    
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                if(A[j-1]==B[i-1] || B[i-1]=='?'){ //uf both characters match, then it will     be 
                //same as prev
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(B[i-1]=='*'){ //take any example, it will satisfy this 
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[r][c];
        
        }
};