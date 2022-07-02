class Solution {
public:
    
    bool isCyclic(int curr, vector<vector<int>> &adj, vector<bool> vis, vector<bool> &chk){
         if(vis[curr]){ //i visited this node earlier in this same iteration, so def cyclic;
            return 1;
        }
        if(chk[curr]){ //i've checked this node before and it's not cyclic;
            return 0; 
        }
        vis[curr]=1;
        for(auto i: adj[curr]){
            if(!chk[i] && isCyclic(i, adj, vis, chk)){
                return 1;
            }
        }
        vis[curr]=0;
        chk[curr]=1;
        return 0;
    }

    
    bool canFinish(int n, vector<vector<int>>& preReq) {
        //here, since we don't have to print out a schedule, we just need to check if the graph's cyclic;
        //because if it is, then we cant complete all the courses;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, 0), chk(n, 0);
        for(auto i: preReq){
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i=0; i<n; i++){
            if(!chk[i] && isCyclic(i, adj, vis, chk)){
                return 0;
            }
        }
        
        return 1;
    }
};