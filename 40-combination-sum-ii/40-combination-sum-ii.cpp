class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> &v, int k, vector<int> &tmp, int ind){
        if(k==0){
            sol.push_back(tmp);
            return;
        }
        int n=v.size();
        for(int i=ind; i<n; i++){
            if(i>ind && v[i]==v[i-1]) continue;
            if(v[i]>k){
                return;
            }
            tmp.push_back(v[i]);
            solve(v, k-v[i], tmp, i+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, tmp, 0);
        return sol;
    }
};