class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(), start=0, cnt=0, sol=0;
        for(int end=0; end<n; end++){
            if(!nums[end]){
                cnt++;
            }
            if(cnt>k){
                if(nums[start]==0) cnt--;
                start++;
            }
            sol=max(sol, end-start+1);
        }
        return sol;
    }
};