class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if(n2<n1) return findMedianSortedArrays(nums2, nums1);
        int lo=0, hi=n1;
        int n1l, n1r, n2l, n2r;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int rem=(n1+n2+1)/2-mid;
            n1l=(mid>0?nums1[mid-1]:INT_MIN);
            n1r=(mid<n1?nums1[mid]:INT_MAX);
            n2l=(rem>0?nums2[rem-1]:INT_MIN);
            n2r=(rem<n2?nums2[rem]:INT_MAX);
            
            if(n1l<=n2r && n1r>=n2l){
                int n=n1+n2;
                if(n%2){
                    return (double)max(n1l, n2l);
                }
                else{
                    return (double)(max(n1l, n2l)+min(n1r, n2r))/2.0;
                }
            }
            else if(n1l>n2r){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return 0;
    }
};