class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sol=nums[0], cnt=1, n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==sol) cnt++;
            else{
                cnt--;
                if(cnt<0){
                    sol=nums[i];
                    cnt=1;
                }
            }
        }
        return sol;
    }
};