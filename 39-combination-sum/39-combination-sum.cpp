class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> &v, int k, vector<int> tmp, int ind){
        int n=v.size();
        if(k==0){ //when we've got the target;
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
        sort(candidates.begin(), candidates.end()); //so whe any value is greater than target, it will break out from loop;
        solve(candidates, target, tmp, 0); //keeping index as combinations must be unique;
        //so same index won't repeat;
        return sol;
    }
};