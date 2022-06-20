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
            pq.push(x); //this way the node with least time will always come first, so final ans will be minimum;
        }
        int sol=0;
        unordered_set<int> hash; //keep track of visited nodes;
        hash.insert(k);
        while(pq.size()){
            int time=pq.top().first, node=pq.top().second;
            pq.pop();
            if(hash.find(node)!=hash.end()){ //we've seen this node before;
                continue;
            }
            hash.insert(node);
            for(auto x: adj[node]){
                if(hash.find(x.second)!=hash.end()) continue;  //if node's already there, then no pt in pushing it to the pq;
                pq.push({x.first+time, x.second}); //update time;
            }
            sol=max(sol, time);
            if(hash.size()==n){ //all nodes are covered;
                return sol;
            }
        }
        return -1;
    }
};