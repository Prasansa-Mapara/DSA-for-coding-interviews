class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> nums, int curr){
        int n=nums.size();
        if(curr==n){
            sol.push_back(nums);
            return;
        }
        for(int i=curr; i<n; i++){
            swap(nums[i], nums[curr]);
            solve(nums, curr+1);
            swap(nums[i], nums[curr]);
        }
    } 
    
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return sol;
    }
};