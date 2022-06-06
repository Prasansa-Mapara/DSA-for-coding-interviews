class Solution {
public:
    int search(vector<int>& nums, int k) {
        int lo=0, hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==k) return mid;
            if(nums[mid]>=nums[lo]){ //left part is sorted
                if(k>=nums[lo] && k<nums[mid]){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }                
            } 
            else{ //right part is sorted
                if(k>nums[mid] && k<=nums[hi]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        return -1;
    }
};