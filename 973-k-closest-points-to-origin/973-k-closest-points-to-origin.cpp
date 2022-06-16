#define piv pair<long long int, vector<int>> 

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> sol;
        priority_queue<piv> pq;
        for(auto i: points){
            long long int dist=i[0]*i[0]+i[1]*i[1];
            pq.push({dist, i});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()){
            sol.push_back(pq.top().second);
            pq.pop();
        }
        return sol;
    }
};