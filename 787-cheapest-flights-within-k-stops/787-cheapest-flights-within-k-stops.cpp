#define pii pair<int, int>
#define ppi pair<int, pii>
#define ff first
#define ss second

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq; //{price, {dest, stops}};
        pq.push({0, {src, 0}});
        vector<vector<pii>> adj(n);
        for(auto f: flights){
            adj[f[0]].push_back({f[2], f[1]}); //source->[{price, dest}];
        }
        vector<pii> dp(n); //{price, stops};
        for(int i=0; i<n; i++){
            dp[i]={INT_MAX, INT_MAX}; //initially the price to reach all nodes is inf,
            //and so are the number of stops;
        }
        dp[src]={0, 0};
        
        while(pq.size()){
            int price=pq.top().ff, curr=pq.top().ss.ff, stop=pq.top().ss.ss;
            pq.pop();
            
            if(curr==dst) return price;
            if(stop==k+1) continue;
            
            for(auto p: adj[curr]){ //p will be a pair;
                int newP=p.ff, newD=p.ss;
                if(newP+price < dp[newD].ff){
                    pq.push({newP+price, {newD, stop+1}});
                    dp[newD]={newP+price, stop};
                }
                else if(stop < dp[newD].ss){
                    pq.push({newP+price, {newD, stop+1}});
                }
            }
        }
        return -1;
    }
};