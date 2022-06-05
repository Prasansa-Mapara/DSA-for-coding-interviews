class Solution {
public:
    vector<string> sol;
    unordered_set<string> dick;
    
    void solve(string s, int curr, vector<string> tmp){
        int n=s.size();
        if(curr==n){
            string x; int sz=tmp.size();
            for(int i=0; i<sz-1; i++){
                x+=tmp[i]+" ";
            }
            x+=tmp[sz-1];
            sol.push_back(x);
            return;
        }
        for(int ed=curr; ed<n; ed++){
            string x=s.substr(curr, ed-curr+1);
            if(dick.find(x)!=dick.end()){ //this string is found in dictionary;
                tmp.push_back(x);
                solve(s, ed+1, tmp);
                tmp.pop_back(); //backtrack;
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i: wordDict){
            dick.insert(i);
        }
        vector<string> tmp;
        solve(s, 0, tmp);
        return sol;
    }
};