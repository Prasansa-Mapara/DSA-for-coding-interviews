class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(), v.end());
        vector<vector<int>> sol;
        sol.push_back(v[0]);
        int ind=0;
        for(int i=1; i<n; i++){
            if(v[i][0]<=sol[ind][1]){
                sol[ind][1]=max(sol[ind][1], v[i][1]);
                sol[ind][0]=min(sol[ind][0], v[i][0]);
            }
            else{
                sol.push_back(v[i]);
                ind++;
            }
        }
        return sol;
    }
};