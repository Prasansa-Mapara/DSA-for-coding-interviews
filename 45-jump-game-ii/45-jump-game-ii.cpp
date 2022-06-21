class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(), curEnd=0, curFar=0, jumps=0;
        for(int i=0; i<n-1; i++){
            curFar=max(curFar, nums[i]+i);
            if(i==curEnd){
                jumps++;
                curEnd=curFar;
            }
        }
        return jumps;
    }
};