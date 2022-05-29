class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), l=0, r=n-1, lMx=0, rMx=0, sol=0;
        while(l<r){ 
            if(height[l]<=height[r]){ //there's already a wall on right side, so lMx will
                //obviousy be the min (among lMx, and rMx), so for trapped water we'll 
                //only consider lMx;
                if(height[l]>=lMx){ //there's no wall on left side;
                    lMx=height[l];
                }
                else{ //we've a higher wall on the left side;
                    sol+=lMx-height[l];
                }
                l++;
            }
            else{ //there's already a wall on left side;
                if(height[r]>=rMx){ //no wall on right side;
                    rMx=height[r];
                }
                else{
                    sol+=rMx-height[r]; //there's a higher wall on right side so water can be trapped;
                }
                r--;
            }
        }
        return sol;
    }
};