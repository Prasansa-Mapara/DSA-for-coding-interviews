class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq; //max heap;
        for(auto pt: points){
            int x=pt[0], y=pt[1];
            int distance=(x*x)+(y*y);
            pq.push({distance, pt});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> sol;
        while(pq.size()){
            sol.push_back(pq.top().second);
            pq.pop();
        }
        return sol;
    }
};