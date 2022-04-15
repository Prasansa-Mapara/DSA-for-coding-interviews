class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int x=mat[i-1][j];
                if((j-1)>=0) x=min(x, mat[i-1][j-1]);
                if((j+1)<n) x=min(x, mat[i-1][j+1]);
                mat[i][j]+=x;
            }
        }
        return *min_element(mat[n-1].begin(), mat[n-1].end());
    }
};