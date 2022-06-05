class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size(), lo=mat[0][0], hi=mat[n-1][n-1];
        while(lo<hi){
            int mid=lo+(hi-lo)/2, cnt=0;
            for(int i=0; i<n; i++){
                cnt+=upper_bound(mat[i].begin(), mat[i].end(), mid)-mat[i].begin();
            }
            if(cnt<k){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return hi;
    }
};