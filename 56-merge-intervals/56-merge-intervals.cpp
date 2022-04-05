class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(), v.end());
        int curr=0, i=1;
        while(i<n){
            if(v[i][0]<=v[curr][1]){
                v[curr][0]=min(v[i][0], v[curr][0]);
                v[curr][1]=max(v[i][1], v[curr][1]);
                i++;
            }
            else{
                curr++;
                v[curr][0]=v[i][0];
                v[curr][1]=v[i][1];
                i++;
            }
        }
        return {v.begin(), v.begin()+curr+1};
    }
};