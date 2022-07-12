#define ll unsigned long

class Solution {
public:
    int numDistinct(string s, string t) {
        int ns=s.size(), nt=t.size();
        if(ns<nt) return 0;
        if(ns==nt){
            if(s==t) return 1;
            return 0;
        }
        
        //i can't skip any chars from t;
        //since we want the total number of ways, we'll add both;
        //if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1] + dp[i-1][j]; 
        //above approach is number of ways i select this char+ number of ways i dont select this char;
        //else dp[i][j]=dp[i-1][j]; //if they dont match, then i cant select this char;
        
        vector<vector<ll>> dp(ns+1, vector<ll>(nt+1, 0));
        
        for(int i=0; i<=ns; i++){ //i dont take any chars from t;
            dp[i][0]=1; //so total number of ways is 1(don't take this char);
        }
        
        for(int i=1; i<=ns; i++){
            for(int j=1; j<=nt; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]+=dp[i-1][j-1];
                }
                dp[i][j]+=dp[i-1][j];
            }
        }
        
        return dp[ns][nt];
    }
};