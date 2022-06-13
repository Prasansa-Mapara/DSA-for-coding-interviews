class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        //since constant extra space, i cant use hash;
        //so will have to use 2 ptrs;
        int i=0, j=nums.size()-1;
        while(i<j){
            int x=nums[i]+nums[j];
            if(x==k){
                return {i+1, j+1};
            }
            else if(x<k){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};