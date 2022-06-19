#define pii pair<int, int>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n=pts.size();
        //this ques is basically finding a mst; 
        //the only diff btwn std algo and this is tht edges are not given;
        priority_queue<pii, vector<pii>, greater<pii>> pq; //min heap;
        unordered_set<int> hash;
        pq.push({0, 0}); //dist for first node is 0;
        int sol=0;
        while(pq.size()){
            int dist=pq.top().first, i=pq.top().second;
            pq.pop();
            if(hash.find(i)!=hash.end()) continue;
            hash.insert(i); //so tht we wont form a loop;
            sol+=dist;
            for(int j=0; j<n; j++){
                if(hash.find(j)!=hash.end()) continue;
                int curr=abs(pts[j][0]-pts[i][0])+abs(pts[j][1]-pts[i][1]); //dist of the node in consideration with the current node;
                pq.push({curr, j});
            }
        }
        return sol;
    }
};