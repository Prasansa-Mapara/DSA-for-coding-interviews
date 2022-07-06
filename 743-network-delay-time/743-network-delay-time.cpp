#define pii pair<int, int>
#define ff first
#define ss second

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq; //time->node;
        vector<vector<pii>> adj(n+1);
        unordered_set<int> hash;
        pq.push({0, k}); //it will always store min time;
        int sol=0;
        
        for(auto i: times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        while(pq.size()){
            int currT=pq.top().ff, node=pq.top().ss;
            pq.pop();
            if(hash.find(node)!=hash.end()) continue; //we've visited this node before;
            hash.insert(node);
            sol=max(sol, currT);
            
            for(auto i: adj[node]){
                int newNode=i.ff, newTime=i.ss;
                if(hash.find(newNode)!=hash.end()){
                    continue;
                }
                pq.push({currT+newTime, newNode});
            }
        }
        
        if(hash.size()<n) return -1; //all the nodes were not covered;
        return sol;
    }
};