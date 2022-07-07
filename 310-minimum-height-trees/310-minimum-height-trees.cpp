class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> cntr(n, 0);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            cntr[i[0]]++; cntr[i[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(cntr[i]<=1){
                q.push(i); //storing all leaf nodes;
                cntr[i]--;
            }
        }
        
        while(n>2){
            int l=q.size();
            n-=l;
            while(l--){
                int curr=q.front(); 
                q.pop();
                for(auto i: adj[curr]){
                    if(cntr[i]==2){
                        q.push(i);
                    }
                    cntr[i]--;
                }
            }
        }
        
        vector<int> sol;
        while(q.size()){
            sol.push_back(q.front());
            q.pop();
        }
        
        return sol;
    }
};