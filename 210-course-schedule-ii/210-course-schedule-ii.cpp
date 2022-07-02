class Solution {
public:
    vector<int> sol;
    
    bool isCyclic(int curr, vector<vector<int>> &adj, vector<bool> &chk, vector<bool> vis){
        if(vis[curr]){
            return 1;
        }
        vis[curr]=1;
        for(auto i: adj[curr]){
            if(!chk[i]){
                if(isCyclic(i, adj, chk, vis)){
                    return 1;
                }
            }
        }
        chk[curr]=1;
        sol.push_back(curr);
        return 0;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& preReq) {
        //just gotta do dfs, then reverse it;
        vector<bool> chk(n, 0), vis(n, 0); //will need it to keep track of checked as well as visited nodes
        //as if cyclic then empty array should be returned;
        
        vector<vector<int>> adj(n);
        for(auto i: preReq){
            adj[i[0]].push_back(i[1]);
        }
        for(int i=0; i<n; i++){
            if(!chk[i]){
                if(isCyclic(i, adj, chk, vis)){
                    return {};
                }
            }
        }
        //reverse(sol.begin(), sol.end());
        return sol;
    }
};