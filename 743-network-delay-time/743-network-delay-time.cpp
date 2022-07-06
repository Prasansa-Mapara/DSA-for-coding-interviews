#define pii pair<int, int>
#define ff first
#define ss second

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //here, there's only one source(k);
        //graph doesn't have any negative weights;
        //we need the shortest path;
        //min time will be the max time at which signal reaches all nodes;
        //so we want the max time to be least, so, signal should reach all nodes at least possible time;
        //so it is a shortest path question;
        //hence, Dijsktra's algo;
        
        /*priority_queue<pii, vector<pii>, greater<pii>> pq; //{time->node}
        vector<bool> vis(n+1, 0);
        int cnt=0, sol=0; //cnt will keep track of the number of visited nodes;
        
        vector<vector<pii>> adj(n+1);
        for(auto i: times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        pq.push({0, k});
        while(cnt<n && pq.size()){
            int time=pq.top().ff, node=pq.top().ss;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            cnt++;
            sol=max(sol, time);
            
            for(auto i: adj[node]){
                int curTime=i.ss, curNode=i.ff;
                if(vis[curNode]) continue;
                pq.push({time+curTime, curNode});
            }
        }
        
        if(cnt<n) return -1; //all nodes were not covered;
        return sol;*/
        
        
        //trying the same using bellman ford (i.e. dp) algo;
        
        vector<vector<int>> dp(n, vector<int>(n+1, INT_MAX));
        for(int i=0; i<n; i++){
            dp[i][k]=0; //time taken by a signal to reach the source node with at most i relaxations;
        }
        int ind=n-1;
        for(int i=1; i<n; i++){ //cuz with 0 relaxations, it can only reach src node;
            for(auto t: times){
                int u=t[0], v=t[1], w=t[2];
                if(dp[i-1][u]!=INT_MAX) dp[i][v]=min(dp[i-1][u]+w, dp[i][v]);
            }
            if(dp[i]==dp[i-1]){
                ind=i;
                break;
            }
        }
        int sol=0;
        for(int i=1; i<=n; i++){
            sol=max(sol, dp[ind][i]);
        }
        return sol==INT_MAX?-1: sol;
    }
};