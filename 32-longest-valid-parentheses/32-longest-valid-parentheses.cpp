class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n<=1) return 0;
        vector<int> dp(n, 0);
        //dp[i] will store the len of max valid substring ending at ith index;
        for(int i=1; i<n; i++){
            if(s[i]==')'){ //because a valid substring can only end with ')';
                if(s[i-1]=='('){
                    if(i>=2) dp[i]=dp[i-2]+2; //obvious;
                    else dp[i]=2;
                }
                else{
                    int prev=i-dp[i-1]-1; //prev is the index before previous valid substring;
                    if(prev>=0 && s[prev]=='('){
                        if(prev>=1) dp[i]=dp[i-1]+2+dp[prev-1]; //if thats opening, then 2 will be added
                        //along with len of subtring previous to prev, cuz they might be connected now;
                        else dp[i]=dp[i-1]+2;
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};