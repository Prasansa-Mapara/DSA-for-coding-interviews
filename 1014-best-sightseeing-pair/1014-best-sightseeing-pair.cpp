class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n=v.size(), sol=INT_MIN, tmp=v[0]-1;
        for(int i=1; i<n; i++){
            sol=max(sol, v[i]+tmp);
            tmp--;
            tmp=max(tmp, v[i]-1);
        }
        return sol;
    }
};