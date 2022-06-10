class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //if a smaller rectangle comes, then we'll be in trouble; 
        //so we'll strictly maintain an increasing order;
        
        stack<pair<int, int>> st; //height->index;
        //not storing indices directly cuz as we remove the larger height elements, we'll need to store that last index cuz it can go both left and right sides;
        
        int n=heights.size(), area=0;
        for(int i=0; i<n; i++){
            if(st.empty() || heights[i]>=st.top().first){
                st.push({heights[i], i});
            }
            else{
                int j;
                while(st.size() && heights[i]<st.top().first){
                    j=st.top().second; //curr element can go upto j in left side as its height is less than height of j;
                    //we found the right index;
                    area=max(area, st.top().first*(i-j));
                    st.pop();
                }
                st.push({heights[i], j});
            }
        }
        
        while(st.size()){
            area=max(area, st.top().first*(n-st.top().second));
            st.pop();
        }
        
        return area;
    }
};