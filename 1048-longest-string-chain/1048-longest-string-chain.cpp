class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<pair<int, string>> v;
        for(auto s: words){
            v.push_back({s.size(), s});
        }
        sort(v.begin(), v.end());
        int n=v.size();
        vector<int> dp(n, 1);
        unordered_map<string, int> hash;
        for(int i=0; i<n; i++){
            hash[v[i].second]=i;
        }
        for(int i=0; i<n; i++){
            string s=v[i].second; 
            int sz=v[i].first;
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