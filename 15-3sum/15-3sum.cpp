class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
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
                    sol.push_back(v);
                    while(j<k && nums[j]==v[1]){
                        j++;
                    }
                    while(k>j && nums[k]==v[2]){
                        k--;
                    }
                }
            }
            while((i+1)<(n-2) && nums[i+1]==nums[i]){
                i++;
            }
        }
        return sol;
    }
};