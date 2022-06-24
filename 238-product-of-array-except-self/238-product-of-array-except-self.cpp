class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int prod=1;
        int z=0; //keep a track of number of 0s;
        vector<int> sol;
        for(auto i:nums){
            if(i) prod*=i;
            else z++;
        }
        for(auto i:nums){
            if(i){
                if(z) sol.push_back(0);
                else{
                    sol.push_back(prod/i);
                }
            }
            else{
                if(z-1){
                    sol.push_back(0);
                }
                else{
                    sol.push_back(prod);
                }
            }
        }
        return sol;
    }
};