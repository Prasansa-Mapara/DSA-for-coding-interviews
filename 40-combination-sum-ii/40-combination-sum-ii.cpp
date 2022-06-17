class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> &nums, int curr, vector<int> tmp, int k){
        if(k==0){
            sol.push_back(tmp);
            return;
        }
        else if(k<0) return;
        int n=nums.size();
        for(int i=curr; i<n; i++){
            if(i!=curr && nums[i]==nums[i-1]) continue;
            if((k-nums[i])>=0){
                tmp.push_back(nums[i]);
                solve(nums, i+1, tmp, k-nums[i]);
                tmp.pop_back();
            }
            else return;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        vector<int> tmp;
        sort(v.begin(), v.end());
        solve(v, 0, tmp, k);
        return sol;
    }
};