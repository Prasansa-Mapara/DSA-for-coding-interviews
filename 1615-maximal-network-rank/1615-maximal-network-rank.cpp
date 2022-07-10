class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //we've to calculate max network rank of all pairs of different cities;
        vector<vector<int>> adj(n, vector<int> (n, 0));
        vector<int> inDeg(n, 0);
        for(auto r: roads){
            adj[r[0]][r[1]]=1;
            adj[r[1]][r[0]]=1;
        
            inDeg[r[0]]++;
            inDeg[r[1]]++;
        }
        
        int sol=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){ //cuz we gotta calculate for all pairs;
                sol=max(sol, inDeg[i]+inDeg[j]-adj[i][j]);
            }
        }
        
        return sol;
    }
};