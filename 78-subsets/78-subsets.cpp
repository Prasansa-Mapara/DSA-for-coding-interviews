class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> &nums, int curr, vector<int> tmp){
        int n=nums.size();
        sol.push_back(tmp);
        for(int i=curr; i<n; i++){
            tmp.push_back(nums[i]);
            solve(nums, i+1, tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        solve(nums, 0, tmp);
        return sol;
    }
};