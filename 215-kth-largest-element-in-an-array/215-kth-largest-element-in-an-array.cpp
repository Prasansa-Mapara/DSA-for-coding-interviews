class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0, pivot=n-1, ind=n-k;
      
        while(left<=pivot){ 
            int tmp=left;
            for(int i=left; i<pivot; i++){ 
                if(nums[i]<=nums[pivot]){
                    swap(nums[i], nums[tmp]);
                    tmp++;
                }
            }
            swap(nums[pivot], nums[tmp]); //all the elements before tmp are smaller than or equal to pivot;
            if(tmp==ind){
                return nums[ind];
            }
            else if(tmp<ind){
                left=tmp+1;
            }
            else{
                pivot=tmp-1;
            }
        }
        
        return -1;
    }
};