class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n=pts.size(), cost=0;
        vector<int> dist(n, INT_MAX);
        dist[0]=0;
        unordered_set<int > hash;
        hash.insert(0);
        int curr=0;
        
        while(hash.size()<n){
            int curMin=INT_MAX, ind;
            hash.insert(curr);
            for(int i=0; i<n; i++){
                if(hash.find(i)!=hash.end()){
                    continue;
                }
                int x=abs(pts[i][0]-pts[curr][0])+abs(pts[i][1]-pts[curr][1]);
                dist[i]=min(dist[i], x);
                if(dist[i]<curMin){
                    curMin=dist[i];
                    ind=i;
                }
            }
            if(curMin<INT_MAX)cost+=curMin;
            curr=ind;
        }
        
        return cost;
    }
};