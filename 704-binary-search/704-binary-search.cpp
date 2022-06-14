class Solution {
public:
    int search(vector<int>& nums, int k) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==k){
                return mid;
            }
            else if(nums[mid]<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};