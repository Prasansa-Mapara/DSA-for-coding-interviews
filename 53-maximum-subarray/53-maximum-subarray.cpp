class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), maxSum=INT_MIN, currSum=0;
        for(int i=0; i<n; i++){
            currSum+=nums[i];
            maxSum=max(currSum, maxSum);
            if(currSum<0) currSum=0;
        }
        return maxSum;
    }
};