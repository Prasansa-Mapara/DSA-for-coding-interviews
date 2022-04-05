class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1;
        int area=INT_MIN;
        while(i<j){
            int curr=min(height[i], height[j]);
            area=max(area, curr*(j-i));
            if(height[i]<height[j]){
                i++;
            }
            else if(height[j]<height[i]){
                j--;
            }
            else{
                if(height[i+1]>height[j-1]){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return area;
    }
};