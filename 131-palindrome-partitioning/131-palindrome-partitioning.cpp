class Solution {
public:
    vector<vector<string>> sol;
    vector<vector<bool>> dp;
    
    void solve(string &s, int st, vector<string> curr){
        int n=s.size();
        if(st>=n){
            sol.push_back(curr);
            return;
        }
        for(int j=st; j<n; j++){
            if(s[st]==s[j]){
                if((j-st>=2 && dp[st+1][j-1]) || j-st<2){
                    dp[st][j]=1;
                    curr.push_back(s.substr(st, j-st+1));
                    solve(s, j+1, curr);
                    curr.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        int n=s.size();
        vector<vector<bool>> tmp(n, vector<bool>(n, 0));
        dp=tmp;
        solve(s, 0, curr); 
        return sol;
    }
};