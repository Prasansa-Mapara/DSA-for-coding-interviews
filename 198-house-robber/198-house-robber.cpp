class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(); 
        for(int i=2; i<n; i++){
            int mx=INT_MIN;
            for(int j=i-2; j>=0; j--){
                mx=max(mx, nums[j]);
            }
            nums[i]+=mx;
        }
        return *max_element(nums.begin(), nums.end());
    }
};