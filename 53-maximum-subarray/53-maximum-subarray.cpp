class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), curr=0, sol=INT_MIN;
        for(auto i:nums){
            curr+=i;
            sol=max(sol, curr);
            if(curr<0) curr=0;
        }
        return sol;
    }
};