class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        nth_element(nums.begin(), nums.begin()+n-k, nums.end());
        //first, sorted_position, last;
        //so, sorted_position, will have the element that is in its correct position if the array is sorted;
        //so other parts of the array is still unsorted, but this part is;
        return nums[n-k];
    }
};