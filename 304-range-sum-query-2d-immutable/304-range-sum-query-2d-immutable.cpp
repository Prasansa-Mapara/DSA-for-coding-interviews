class NumMatrix {
public:
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>> tmp(r+1, vector<int>(c+1, 0));
        dp=tmp;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]-dp[i][j]+mat[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */