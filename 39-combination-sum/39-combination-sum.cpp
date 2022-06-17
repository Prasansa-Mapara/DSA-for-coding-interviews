class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> &v, vector<int> tmp, int k, int curr){
        int n=v.size();
        if(k==0){
            sol.push_back(tmp);
            return;
        }
        for(int i=curr; i<n; i++){
            if((k-v[i])>=0){
                tmp.push_back(v[i]);
                solve(v, tmp, k-v[i], i);
                tmp.pop_back();
            }
            else{
                return;
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        vector<int> tmp;
        sort(v.begin(), v.end());
        solve(v, tmp, k, 0);
        return sol;
    }
};