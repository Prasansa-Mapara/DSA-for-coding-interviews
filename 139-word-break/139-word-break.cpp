class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for(auto s: wordDict) hash.insert(s);
        int n=s.size();
        vector<int> dp(n+1, 0);
        dp[0]=1; //if i dont take any word, then its valid;
        for(int ed=0; ed<n; ed++){
            for(int st=ed; st>=0; st--){
                string tmp=s.substr(st, ed-st+1);
                if(hash.find(tmp)!=hash.end()){
                    if(dp[st]){
                        dp[ed+1]=1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};