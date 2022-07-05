class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n=pts.size();
        int cost=0;
        vector<int> dst(n, INT_MAX);
        //lets start from the first point;
        dst[0]=0;
        unordered_set<int> hash;
        int curr=0;
        hash.insert(curr);
        while(hash.size()<n){
            int curMin=INT_MAX; //min distance from the current pt 
            //or from any of the connected points;
            int nxtCur; //the next node that we'll consider;
            hash.insert(curr);
            for(int i=0; i<n; i++){
                if(hash.find(i)!=hash.end()){ //we've already taken this point;
                    continue;
                }
                int curD=abs(pts[curr][0]-pts[i][0])+abs(pts[curr][1]-pts[i][1]);
                dst[i]=min(curD, dst[i]);
                if(dst[i]<curMin){
                    curMin=dst[i];
                    nxtCur=i; 
                }
            }
            if(curMin==INT_MAX) break;
            cost+=curMin;
            curr=nxtCur;
        }
        return cost;
    }
};