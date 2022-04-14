bool func(string a, string b){
    return a.size()<b.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), func);
        int n=words.size(), sol=1;
        unordered_map<string, int> dp;
        for(int i=0; i<n; i++){
            dp[words[i]]=1;
        }
        for(int i=0; i<n; i++){
            string s=words[i]; 
            int sz=s.size();
            for(int j=0; j<sz; j++){
                string tmp=s;
                tmp.erase(tmp.begin()+j);
                if(dp.find(tmp)!=dp.end()){
                    dp[s]=max(dp[s], 1+dp[tmp]);
                    sol=max(sol, dp[s]);
                }
            }
        }
        return sol;
    }
};