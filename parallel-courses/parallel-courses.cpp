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
        int c=0, sem=0;
        
        for(int i=1; i<=n; i++){
            if(inDeg[i]==0){
                inDeg[i]--;
                q.push(i);
                c++; //i can take this course;
            }
        }
        
        while(q.size()){
            int sz=q.size();
            sem++;
            while(sz--){
                int curr=q.front();
                q.pop();
                for(auto i: adj[curr]){
                    inDeg[i]--; //cuz now i've taken course curr, so that's one less preReq for i;
                    if(inDeg[i]==0){ //i can now take this course;
                        q.push(i);
                        c++;
                    }
                }
            }
        }
        
        return c==n?sem:-1;
    }
};