class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> &nums, int curr, vector<int> tmp){
        sol.push_back(tmp);
        int n=nums.size();
        for(int i=curr; i<n; i++){
            if(i!=curr && nums[i]==nums[i-1]) continue; //we dont want any duplicates;
            tmp.push_back(nums[i]);
            solve(nums, i+1, tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, tmp);
        return sol;
    }
};