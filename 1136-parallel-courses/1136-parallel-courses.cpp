class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& rel) {
        vector<vector<int>> adj(n+1);
        vector<int> inDeg(n+1, 0);
        for(auto r: rel){
            inDeg[r[1]]++;
            adj[r[0]].push_back(r[1]);
        }
        queue<int> q;
        int sem=0, courses=0;
        for(int i=1; i<=n; i++){
            if(inDeg[i]==0){
                q.push(i);
                courses++;
            }
        }
        
        while(q.size()){
            sem++;
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                for(auto i: adj[curr]){
                    inDeg[i]--;
                    if(inDeg[i]==0){
                        q.push(i);
                        courses++;
                    }
                }
            }
        }
        
        return courses==n?sem: -1;
    }
};