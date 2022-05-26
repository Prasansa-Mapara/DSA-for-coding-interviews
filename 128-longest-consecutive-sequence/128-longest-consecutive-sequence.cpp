class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sol=1, cnt=1, n=nums.size();
        if(n==0) return 0;
        for(int i=1; i<n; i++){
            if(nums[i]==(nums[i-1]+1)){
                cnt++;
                sol=max(sol, cnt);
            }
            else if(nums[i]>(nums[i-1]+1)){
                cnt=1;
            }
            else{
                
            }
        }
        return sol;
    }
};