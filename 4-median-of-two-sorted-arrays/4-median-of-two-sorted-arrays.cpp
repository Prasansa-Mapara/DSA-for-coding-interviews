class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        if(m>n){
            swap(nums1, nums2);
            swap(m, n);
        }
        int lo=0, hi=m;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2, rem=((m+n+1)/2)-mid;
            int aL, aR, bL, bR;
            aL=(mid>0)?(nums1[mid-1]):(INT_MIN);
            aR=(mid<m)?(nums1[mid]):(INT_MAX);
            bL=(rem>0)?(nums2[rem-1]):(INT_MIN);
            bR=(rem<n)?(nums2[rem]):(INT_MAX);
            
            if(aL<=bR && bL<=aR){
                int tot=m+n;
                if(tot%2){
                    return (double)max(aL, bL);
                }
                else{
                    return (double)(max(aL, bL)+min(aR, bR))/2.0;
                }
            }
            else if(aL>bR){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        
        return 0;
    }
};