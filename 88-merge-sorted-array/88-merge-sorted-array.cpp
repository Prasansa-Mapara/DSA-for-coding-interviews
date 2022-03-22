/*
Whenever you're trying to solve an array problem in-place, always consider the possibility of iterating backwards instead of forwards through the array. It can completely change the problem, and make it a lot easier.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //merge in nums1;
        //in place merge and sort;
        
        int i=m-1, j=n-1, curr=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[curr--]=nums1[i--];
            }
            else{
                nums1[curr--]=nums2[j--];
            }
        }
        while(i>=0){
            nums1[curr--]=nums1[i--];
        }
        while(j>=0){
            nums1[curr--]=nums2[j--];
        }
    }
};