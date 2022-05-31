class Solution {
public:
    vector<vector<int>> sol;
    set<vector<int>> hash;
    
    //v=[2,3,6,7] k=7
    //2,2,3
    void solve(vector<int> &v, int k, vector<int> tmp, int ind){
        int n=v.size();
        if(k==0){
            sol.push_back(tmp);           
            return;
        }
        for(int i=ind; i<n; i++){
            if(v[i]<=k){
                tmp.push_back(v[i]);
                solve(v, k-v[i], tmp, i);
                tmp.pop_back();
            }
            else{
                return;
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, tmp, 0);
        return sol;
    }
};