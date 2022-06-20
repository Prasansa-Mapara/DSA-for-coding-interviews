#define pii pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n+1);
        for(auto x: times){
            adj[x[0]].push_back({x[2], x[1]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq; //min time will be first;
        for(auto x: adj[k]){
            pq.push(x);
        }
        int sol=0;
        unordered_set<int> hash;
        hash.insert(k);
        while(pq.size()){
            int time=pq.top().first, node=pq.top().second;
            pq.pop();
            if(hash.find(node)!=hash.end()){ //we've seen this node before;
                continue;
            }
            hash.insert(node);
            for(auto x: adj[node]){
                if(hash.find(x.second)!=hash.end()) continue;
                pq.push({x.first+time, x.second});
            }
            sol=max(sol, time);
            if(hash.size()==n){
                return sol;
            }
        }
        return -1;
    }
};