class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int prod=1;
        bool z=0; //if there's a zero present;
        int n=nums.size();
        vector<int> sol(n, 0);
        for(auto i:nums){
            if(i) prod*=i; //keep a track of product of all non-zero numbers;
            else{
                if(!z) z=1;
                else{ //there's more than 1 zero, so sol will have all zeroes;
                    return sol;
                }
            }
        }
        int j=0;
        for(auto i:nums){
            if(i){ //curr num's non-zero;
                if(z) sol[j]=0; //but there's a 0;
                else{
                    sol[j]=prod/i; //no 0 present;
                }
            }
            else{
                sol[j]=prod;
            }
            j++;
        }
        return sol;
    }
};