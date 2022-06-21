class Solution {
public:
    map<pair<int, int>, int> hash; //ind, sum -> ways
    
    int solve(vector<int> &nums, int ind, int k){
        int n=nums.size();
        if(ind==n){
            if(k==0){
                return 1;
            }
            return 0;
        }
        if(hash.find({ind, k})!=hash.end()){
            return hash[{ind, k}];
        }
        hash[{ind, k}]=solve(nums, ind+1, k+nums[ind])+solve(nums, ind+1, k-nums[ind]);
        return hash[{ind, k}];
    }

    int findTargetSumWays(vector<int>& nums, int k) {
        int n=nums.size();
        return solve(nums, 0, k);
    }
};