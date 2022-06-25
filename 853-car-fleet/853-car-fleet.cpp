class Solution {
public:
    int carFleet(int k, vector<int>& pos, vector<int>& speed) {
        int n=pos.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({pos[i], speed[i]});
        }
        sort(v.begin(), v.end());
        //if curr car takes equal or more time than prev car,
        //then they will form a fleet;
        stack<double> st;
        for(int i=0; i<n; i++){
            int pos=v[i].first, speed=v[i].second;
            double curr=(double)(k-pos)/(double)speed;
            while(st.size() && curr>=st.top()){
                st.pop();
            }
            st.push(curr);
        }
        return st.size();
    }
};