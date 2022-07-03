class Solution {
public:
    unordered_map<string, multiset<string>> hash;
    vector<string> sol;
    
    void dfs(string curr){
        while(hash[curr].size()){
            auto i=hash[curr].begin();
            string s=*i;
            hash[curr].erase(i);
            dfs(s);
            
        }
        sol.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto i:tickets){
            hash[i[0]].insert(i[1]);
        }
        dfs("JFK");
        reverse(sol.begin(), sol.end());
        return sol;
    }
};