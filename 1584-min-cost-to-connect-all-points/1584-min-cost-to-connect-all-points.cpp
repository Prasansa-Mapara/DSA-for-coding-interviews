class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        //since the points are fixed, we dont have to keep storing them again and again;
        int n=pts.size(), sol=0;
        vector<int> dist(n, INT_MAX);
        dist[0]=0;
        int ind=0; //curr minimum dist, and its corresponding index;
        unordered_set<int> hash;
        while(hash.size()<n){
            int mn=INT_MAX, j;
            hash.insert(ind);
            for(int i=0; i<n; i++){
                if(hash.find(i)!=hash.end()) continue;
                int curr=abs(pts[i][0]-pts[ind][0])+abs(pts[i][1]-pts[ind][1]);
                if(curr<dist[i]){
                    dist[i]=curr;
                }
                if(dist[i]<mn){
                    mn=dist[i];
                    j=i;
                }
            }
            if(mn==INT_MAX) break;
            sol+=mn;
            ind=j;
        }
        return sol;
    }
};