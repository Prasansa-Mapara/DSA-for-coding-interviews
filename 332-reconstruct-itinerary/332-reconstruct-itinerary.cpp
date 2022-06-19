class Solution {
public:
    vector<string> sol;
    unordered_map<string, vector<string>> hash;
    
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
            hash[x[0]].push_back(x[1]);
        }
        for(auto i=hash.begin(); i!=hash.end(); i++){
            sort(i->second.begin(), i->second.end());
        }
        dfs("JFK");
        reverse(sol.begin(), sol.end());
        return sol;
    }
};