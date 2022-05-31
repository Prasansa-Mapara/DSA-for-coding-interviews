class Solution {
public:
    set<vector<int>> hash;
    
    void solve(vector<int> &nums, int ind, map<int, int> tmp){
        int n=nums.size();
        if(ind==n){
            vector<int> v;
            for(auto i: tmp){
                int j=i.second;
                while(j>0){
                    v.push_back(i.first);
                    j--;
                }
            }
            hash.insert(v);
            return;
        }
        solve(nums, ind+1, tmp);
        tmp[nums[ind]]++;
        solve(nums, ind+1, tmp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> tmp;
        solve(nums, 0, tmp);
        vector<vector<int>> sol;
        for(auto v: hash){
            sol.push_back(v);
        }
        return sol;
    }
};