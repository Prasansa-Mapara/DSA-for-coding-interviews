class Solution {
public:
    vector<int> sol;
    vector<bool> chk;
    
    bool isCyc(int curr, vector<bool> vis, vector<vector<int>> &adj){
        if(vis[curr]){
            return 1;
        }
        if(chk[curr]){
            return 0;
        }
        vis[curr]=1;
        for(auto i: adj[curr]){
            if(!chk[i] && isCyc(i, vis, adj)){
                return 1;
            }
        }
        chk[curr]=1;
        sol.push_back(curr); //we've taken all pre requisites, so now, we can take this course;
        return 0;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& preReq) {
        //this is post-order dfs;
        vector<vector<int>> adj(n);
        for(auto i: preReq){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> vis(n, 0); chk=vis;
        
        for(int i=0; i<n; i++){
            if(!chk[i] && isCyc(i, vis, adj)){
                return {};
            }
        }
        
        return sol;
    }
};