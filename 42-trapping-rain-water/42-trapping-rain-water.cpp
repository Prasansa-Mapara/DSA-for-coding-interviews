class Solution {
public:
    int trap(vector<int>& height) {
        //min(lMax, rMax)-height[i];
        int lMax=0, rMax=0, l=0, r=height.size()-1, sol=0;
        while(l<r){
            if(height[l]>=lMax){
                lMax=height[l];
            }
            if(height[r]>=rMax){
                rMax=height[r];
            }
            int curr=min(height[l], height[r]);
            sol+=min(lMax, rMax)-curr;
            if(lMax<=rMax){
                l++;
            }
            else{
                r--;
            }
        }
        return sol;
    }
};