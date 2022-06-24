class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> sol;
        int r=mat.size(), c=mat[0].size(), rs=0, cs=0, re=r-1, ce=c-1;
        
        while(rs<=re && cs<=ce){
            int i=rs, j=cs;
            for(j=cs; j<=ce; j++){
                sol.push_back(mat[i][j]);
            }
            j=ce;
            for(i=rs+1; i<=re; i++){
                sol.push_back(mat[i][j]);
            }
            i=re;
            for(j=ce-1; j>=cs; j--){
                sol.push_back(mat[i][j]);
            }
            j=cs;
            for(i=re-1; i>rs; i--){
                sol.push_back(mat[i][j]);
            }
            rs++; re--; cs++; ce--;
        }
        
        return vector<int>(sol.begin(), sol.begin()+r*c);
    }
};