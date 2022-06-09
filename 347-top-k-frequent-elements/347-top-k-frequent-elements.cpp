#define pii pair<int, int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(auto i: nums){
            hash[i]++;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto i=hash.begin(); i!=hash.end(); i++){
            pq.push({i->second, i->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> sol;
        while(pq.size()){
            sol.push_back(pq.top().second);
            pq.pop();
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};