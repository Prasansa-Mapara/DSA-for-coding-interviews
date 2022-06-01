class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> v, int ind){
        int n=v.size();
        if(ind==n){
            sol.push_back(v);
            return;
        }
        for(int i=ind; i<n; i++){
            swap(v[i], v[ind]);
            solve(v, ind+1);
            swap(v[i], v[ind]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        solve(nums, 0);
        return sol;
    }
};