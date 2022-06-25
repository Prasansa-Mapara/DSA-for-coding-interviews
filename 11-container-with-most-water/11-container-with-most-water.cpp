class Solution {
public:
    int maxArea(vector<int>& height) {
        //area will be min(h[l], h[r])*(r-l)
        int sol=0, n=height.size(), l=0, r=n-1;
        while(l<r){
            int curr=min(height[l], height[r])*(r-l);
            sol=max(sol, curr);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return sol;
    }
};