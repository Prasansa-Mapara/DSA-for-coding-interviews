class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n=v.size(), sol=INT_MIN, tmp=v[0]-1; //already taking subtracted value;
        for(int i=1; i<n; i++){
            sol=max(sol, v[i]+tmp);
            tmp--; //subtracting for next iteration;
            tmp=max(tmp, v[i]-1); //already taking subtracted value;
        }
        return sol;
    }
};