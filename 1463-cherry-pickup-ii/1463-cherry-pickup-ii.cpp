class Solution {
public:
    int cherryPickup(vector<vector<int>>& mat) {
        //since we've 2 robos, we'll need to check which robo picked which cherry;
        //so apart from normal 2D dp, there's one more constraint, so 3D DP;
        
        int r=mat.size(), c=mat[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
        
        //row of both robos are same, as they moving at same time;
        //col will be different;
        for(int i=r-1; i>=0; i--){
            for(int j=0; j<c; j++){
                for(int k=0; k<c; k++){
                    dp[i][j][k]+=mat[i][j];  //first robo takes the cherries;
                    if(j!=k) dp[i][j][k]+=mat[i][k]; //second robo also collects cherries;
                    
                    if(i==r-1) continue;
                    int tmp=0;
                    for(int jj=j-1; jj<=j+1; jj++){
                        if(jj>=0 && jj<c){
                            for(int kk=k-1; kk<=k+1; kk++){
                                if(kk>=0 && kk<c){
                                   tmp=max(tmp, dp[i+1][jj][kk]); //robo could have come from here;
                                }
                            }
                        }
                    }
                    
                    dp[i][j][k]+=tmp;
                }
            }
        }
        
        return dp[0][0][c-1];
    }
};