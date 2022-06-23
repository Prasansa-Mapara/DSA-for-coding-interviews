class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &v, vector<int>& curr) 
    {
        vector<vector<int>> sol;
        int n=v.size();
        for(int i=0; i<n; i++){
            if(v[i][1]<curr[0]){
                sol.push_back(v[i]);
            }
            else if(curr[1]<v[i][0]){
                sol.push_back(curr);
                curr=v[i];
            }
            else{
                curr[0]=min(curr[0], v[i][0]);
                curr[1]=max(curr[1], v[i][1]);
            }
        }
        sol.push_back(curr);
        return sol;
    }
};