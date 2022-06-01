class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> &v, unordered_set<int> hash, vector<int> tmp){
        int n=v.size();
        if(tmp.size()==n){
            sol.push_back(tmp);
            return;
        }
        for(int i=0; i<n; i++){
            if(hash.find(v[i])==hash.end()){
                tmp.push_back(v[i]);
                hash.insert(v[i]);
                solve(v, hash, tmp);
                tmp.pop_back();
                hash.erase(hash.find(v[i]));
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> hash;
        vector<int> tmp;
        solve(nums, hash, tmp);
        return sol;
    }
};