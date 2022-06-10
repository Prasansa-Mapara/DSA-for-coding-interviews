class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), area=0;
        stack<pair<int, int>> st; 
        for(int i=0; i<n; i++){
            if(st.empty() || st.top().first<=heights[i]){
                st.push({heights[i], i});
            }
            else{
                int j;
                while(st.size() && heights[i]<st.top().first){
                    j=st.top().second;
                    int curr=st.top().first;
                    st.pop();
                    area=max(area, curr*(i-j));
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