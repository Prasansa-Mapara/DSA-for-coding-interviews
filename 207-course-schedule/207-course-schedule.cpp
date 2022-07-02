class Solution {
public:
    
    bool isCyclic(int curr, vector<vector<int>> &adj, vector<bool> vis, vector<bool> &chk){
        if(vis[curr]){ //i visited this node earlier in this same iteration, so def cyclic;
            return 1;
        }
        vis[curr]=1;
        for(auto i: adj[curr]){
            if(!chk[i] && isCyclic(i, adj, vis, chk)){
                //we not directly returning isCyclic here, cuz other node might be cyclic even if the curr node's not; 
                return 1;
            }
        }
        chk[curr]=1; //cuz now we done checking all neighbors of this node;
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
                return 0; //if cyclic then not possible;
            }
        }
        
        return 1;
    }
};