class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<pair<int, int>> st;
        int n=height.size(), sol=0;
        for(int i=0; i<n; i++){
            int ind=i;
            while(st.size() && height[i]<st.top().first){ //prev rectangle can't expand now;
                ind=st.top().second;
                sol=max(sol, st.top().first*(i-st.top().second));
                st.pop();
            }
            st.push({height[i], ind});
        }
        while(st.size()){
            sol=max(sol, st.top().first*(n-st.top().second));
            st.pop();
        }
        return sol;
    }
};