class Solution {
public:
    bool isMatch(string s, string p) {
        int ns=s.length(), np=p.length();
        int cnt=0;
        for(int i=0; i<np; i++){
            if(p[i]!='*'){
                cnt++;
            }
        }
        if(cnt>ns){  //first check wats obvious, if passes this, then go to next step
            return 0;
        }
        vector<vector<bool>> dp(np+1, vector<bool>(ns+1, false)); //since it will be 0, 1
        //makes more sense declaring dp of bool as it will take up 4 times lesser space. 
        dp[0][0]=true; //if both string are null, they match
        
        for(int i=1; i<=np; i++){
            if(p[i-1]=='*' && dp[i-1][0]){
                dp[i][0]=dp[i-1][0]; //if its a star, then if prev string matched then 1
            }
            else{
                break;
            }
        }
    
        for(int i=1; i<=np; i++){ //i take i number of chars from p, 
            for(int j=1; j<=ns; j++){// and j number of chars from s;
                if(s[j-1]==p[i-1] || p[i-1]=='?'){ //uf both characters match, then it will     be 
                //same as prev
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){ //take any example, it will satisfy this 
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[np][ns];
        
        }
};