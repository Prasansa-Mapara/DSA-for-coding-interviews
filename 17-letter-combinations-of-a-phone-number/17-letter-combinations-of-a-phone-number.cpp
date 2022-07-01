class Solution {
public:
    vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> sol;
    
    void solve(string &s, int ind, string curr){
        int n=s.size();
        if(ind==n){
            sol.push_back(curr);
            return;
        }
        int x=s[ind]-'0';
        for(int j=0; j<v[x].size(); j++){
           curr.push_back(v[x][j]);
            solve(s, ind+1, curr);
            curr.pop_back();
        }
    }
    //time complexity for backtrack will be (c in main) multiplied by (for in solve)^(#constraint in the solve function);
    //1*4^n (*n this idk how or why)
    vector<string> letterCombinations(string digits) {
        if(digits=="") return sol;
        solve(digits, 0, "");
        return sol;
    }
};