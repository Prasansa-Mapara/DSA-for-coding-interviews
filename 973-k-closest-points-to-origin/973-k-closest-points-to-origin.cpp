#define piv pair<long long int, vector<int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> sol;
        priority_queue<piv, vector<piv>, greater<piv>> pq;
        for(auto x: points){
            long long int tmp=x[0]*x[0]+x[1]*x[1];
            pq.push({tmp, x});
        }
        while(k--){
            sol.push_back(pq.top().second);
            pq.pop();
        }
        return sol;
    }
};