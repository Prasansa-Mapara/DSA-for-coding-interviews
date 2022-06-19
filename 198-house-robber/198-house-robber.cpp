class Solution {
public:
    int rob(vector<int>& nums) {
        //i can either rob the current house, or not;
        int n=nums.size();
        if(n>1) nums[1]=max(nums[1], nums[0]);
        for(int i=2; i<n; i++){
            nums[i]=max(nums[i]+nums[i-2], nums[i-1]);
        }
        return nums[n-1];
    }
};