class Solution {
public:
    int maxScore(vector<int>& pts, int kk) {
        long long int sol=0, i=0, n=pts.size(), sum=0, k=kk;
        k=min(k, n);
        for(int i=k-1; i>=0; i--){
            sum+=pts[i];
        }
        sol=max(sol, sum);
        int j=n-1;
        for(int i=k-1; i>=0; i--){
            sum-=pts[i];
            sum+=pts[j--];
            sol=max(sol, sum);
        }
        return sol;
    }
};