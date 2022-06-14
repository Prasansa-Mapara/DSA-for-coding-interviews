class Solution {
public:
    vector<string> sol;
    
    void solve(int open, int closed, int &n, string curr){
        if(open==n && closed==n){
            sol.push_back(curr);
            return;
        }
        if(open<n){
            curr+="(";
            solve(open+1, closed, n, curr);
            curr.erase(curr.end()-1); //backtrack;
        }
        if(closed<open){
            curr+=")";
            solve(open, closed+1, n, curr);
            curr.erase(curr.end()-1); //backtrack;
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        solve(0, 0, n, "");
        return sol;
    }
};