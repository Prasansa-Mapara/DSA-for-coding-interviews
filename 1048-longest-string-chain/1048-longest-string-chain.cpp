bool func(string a, string b){
    return a.size()<b.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), func);
        int n=words.size();
        vector<int> dp(n, 1);
        unordered_map<string, int> hash;
        for(int i=0; i<n; i++){
            hash[words[i]]=i;
        }
        for(int i=0; i<n; i++){
            string s=words[i]; 
            int sz=s.size();
            for(int j=0; j<sz; j++){
                string tmp=s;
                tmp.erase(tmp.begin()+j);
                if(hash.find(tmp)!=hash.end()){
                    dp[i]=max(dp[i], 1+dp[hash[tmp]]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};