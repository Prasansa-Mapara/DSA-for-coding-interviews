class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //we gotta find (from the right), first pair of a[i-1]<a[i];
        //1 2 3 5 4 0 -> 1 2 4 0 3 5
        //now no rearranegment on right is possible cuz they all in decreasing order;
        // so now, find a number greater than a[i-1] again start from right as it will be the least possible
        //number greater than a[i-1], swap them, then since we want lexicographically smallest, reverse from a[i];
        
        int n=nums.size();
        for(int i=n-1; i>0; i--){
            if(nums[i-1]<nums[i]){
                for(int j=n-1; j>=i; j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j], nums[i-1]);
                        reverse(nums.begin()+i, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};