class Solution {
public:
    vector<string> sol;
    unordered_map<string, multiset<string>> hash;
    
    void dfs(string curr){
        while(hash[curr].size()){
            string tmp=*hash[curr].begin();
            hash[curr].erase(hash[curr].begin());
            dfs(tmp);
        }
        sol.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x: tickets){
            hash[x[0]].insert(x[1]);
        }
        dfs("JFK");
        reverse(sol.begin(), sol.end());
        return sol;
    }
};