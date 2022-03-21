class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), i=0, j=n-1, p=0;
        while(i<j && p<n){
            if(nums[p]==0){
                if(p>i) swap(nums[p], nums[i]);
                else p++;
                i++;
            }
            else if(nums[p]==2){
                if(p<j) swap(nums[p], nums[j]);
                else p++;
                j--;
            }
            else p++;
        }
        return;
    }
};