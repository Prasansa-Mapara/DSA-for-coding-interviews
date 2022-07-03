class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMx=1, curMn=1, sol=INT_MIN;
        for(auto n: nums){
            int x=n*curMx, y=n*curMn;
            curMx=max(x, max(y, n)); 
            curMn=min(x, min(y, n)); 
            sol=max(sol, curMx); 
        }
        return sol;
    }
};