class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n=pts.size();
        vector<int> dist(n, INT_MAX); //this will store the minimum distance to reach the pt;
        unordered_set<int> hash;
        dist[0]=0;
        hash.insert(0);
        int j=0, sol=0;
        while(hash.size()<n){
            int currMin=INT_MAX, ind; //this will store the min distance and its index;
            hash.insert(j);
            for(int i=0; i<n; i++){
                if(hash.find(i)!=hash.end()) continue;
                int currDist=abs(pts[i][0]-pts[j][0])+abs(pts[i][1]-pts[j][1]);
                dist[i]=min(dist[i], currDist);
                if(dist[i]<currMin){
                    currMin=dist[i];
                    ind=i;
                }
            }
            if(currMin==INT_MAX) break;
            sol+=currMin;
            j=ind;
        }
        return sol;
    }
};