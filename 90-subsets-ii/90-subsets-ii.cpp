class Solution {
public:
    set<vector<int>> hash;
    
    void solve(vector<int> &nums, int ind, map<int, int> tmp){
        int n=nums.size();
        if(ind==n){
            vector<int> v;
            for(auto i: tmp){
                int j=i.second;
                while(j>0){
                    v.push_back(i.first);
                    j--;
                }
            }
            hash.insert(v);
            return;
        }
        solve(nums, ind+1, tmp); //w/o considering this index;
        tmp[nums[ind]]++;        //considering this index;
        solve(nums, ind+1, tmp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> tmp; //here i cant kepe unordered map, cuz then [1,4] and [4,1] will be treated separately;
        //not directly using a vector, cuz we don't wanna count 1,4 and 4,1 twice, this both should mean the same;
        //as no duplicate subset and for a subset, (1,4) and (4,1) is same only, since this isn't a subsequence;
        solve(nums, 0, tmp);
        vector<vector<int>> sol;
        for(auto v: hash){ //used a set so that there will be no duplicates;
            sol.push_back(v);
        }
        return sol;
    }
};