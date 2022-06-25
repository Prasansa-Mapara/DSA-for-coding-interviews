class Solution {
public:
     int carFleet(int k, vector<int>& pos, vector<int>& speed) {
         //cars that reach the destination at the same time is a fleet;
        //faster car will always catch up to the slower car;
         //so prev car will catch up curr car, if time taken by prev car to reach the desti is less than
         //time taken by curr car to reach the desti;
         vector<pair<int, int>> v;
         int n=pos.size();
         for(int i=0; i<n; i++){
             v.push_back({pos[i], speed[i]});
         }
         sort(v.begin(), v.end());
         
         stack<double> st;
         for(int i=0; i<n; i++){
             double curr=(double)(k-v[i].first)/(double)v[i].second; //time taken by curr car to reach desti;
             while(st.size() && curr>=st.top()){ //if prev car reaches desti at same time or more time than curr car,
                 //then they will end up meeting;
                 st.pop();
             }
             st.push(curr);
         }
         return st.size();
    }
};