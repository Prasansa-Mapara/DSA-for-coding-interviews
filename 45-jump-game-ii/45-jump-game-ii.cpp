class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(), jumps=0;
        int last=0, farthest=0;
        for(int i=0; i<n-1; i++){
            farthest=max(farthest, i+nums[i]);
            if(last==i){
                jumps++;
                last=farthest;
            }
        }
        return jumps;
    }
};