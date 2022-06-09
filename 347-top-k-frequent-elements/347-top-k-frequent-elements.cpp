//can be solved in linear time using bucket sort; 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> buck(n+1);
        unordered_map<int, int> hash;
        for(auto i: nums){
            hash[i]++;
        }
        for(auto i=hash.begin(); i!=hash.end(); i++){
            buck[i->second].push_back(i->first);
        }
        vector<int> sol;
        for(int i=n; i>=0 && k; i--){
            for(int j=0; j<buck[i].size() && k; j++){
                sol.push_back(buck[i][j]);
                k--;
            }
        }
        return sol;
    }
};