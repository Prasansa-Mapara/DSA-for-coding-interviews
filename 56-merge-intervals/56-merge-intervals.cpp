class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int i=0, j=1, n=v.size();
        sort(v.begin(), v.end());
        while(j<n){
            if(v[i][1]>=v[j][0]){
                v[i][0]=min(v[i][0], v[j][0]);
                v[i][1]=max(v[i][1], v[j][1]);
            }
            else{
                i++;
                v[i]=v[j];
            }
            j++;
        }
        return vector<vector<int>>(v.begin(), v.begin()+i+1);
    }
};