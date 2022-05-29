class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sol=0, tmp=0, i=0, n=nums.size();
        while(i<n){
            if(nums[i]==1){
                tmp++;
            }
            else{
                tmp=0;
            }
            sol=max(sol, tmp);
            i++;
        }
        return sol;
    }
};