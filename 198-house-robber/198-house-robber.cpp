class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(); 
        for(int i=2; i<n; i++){
           if(i-3>=0) nums[i]+=max(nums[i-2], nums[i-3]);
           else nums[i]+=nums[i-2];
        }
        return *max_element(nums.begin(), nums.end());
    }
};