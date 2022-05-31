class Solution {
public:
    vector<vector<string>> sol;
    
    void solve(string &s, int st, vector<string> tmp, vector<vector<bool>> &dp){
        int n=s.size();
        if(st>=n){
            sol.push_back(tmp);
            return;
        }
        for(int ed=st; ed<n; ed++){
            string curr=s.substr(st, ed-st+1);
            if(s[st]==s[ed] && ((ed-st)<=2 || dp[st+1][ed-1])){
                tmp.push_back(curr);
                dp[st][ed]=1;
                solve(s, ed+1, tmp, dp);
                tmp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        vector<string> tmp;
        solve(s, 0, tmp, dp);
        return sol;
    }
};