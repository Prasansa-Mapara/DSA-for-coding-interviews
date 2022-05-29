class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> hash;
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            int req=-nums[i];
            int j=i+1, k=n-1;
            while(j<k){
                int curr=nums[j]+nums[k];
                if(curr<req){
                    j++;
                }
                else if(curr>req){
                    k--;
                }
                else{
                    vector<int> v={nums[i], nums[j], nums[k]};
                    if(hash.find(v)==hash.end()){
                        hash.insert(v);
                        sol.push_back(v);
                    }
                    j++;
                }
            }
        }
        return sol;
    }
};