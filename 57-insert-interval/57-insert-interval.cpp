class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& curr) {
        int n=v.size();
        vector<vector<int>> sol;
        for(int i=0; i<n; i++){
            if(v[i][1]<curr[0]){
                sol.push_back(v[i]);
            }
            else if(curr[1]<v[i][0]){
                sol.push_back(curr);
                curr=v[i];
            }
            else{
                curr[0]=min(v[i][0], curr[0]);
                curr[1]=max(v[i][1], curr[1]);
            }
        }
        sol.push_back(curr);
        return sol;
    }
};