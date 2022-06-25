class Solution {
public:
    int maxArea(vector<int>& height) {
        //area will be min(maxL, maxR)*(r-l)
        int maxR=0, maxL=0, sol=0, n=height.size(), l=0, r=n-1;
        while(l<r){
            maxR=max(maxR, height[r]);
            maxL=max(maxL, height[l]);
            int curr=min(maxL, maxR)*(r-l);
            sol=max(sol, curr);
            if(maxL<maxR){
                l++;
            }
            else{
                r--;
            }
        }
        return sol;
    }
};