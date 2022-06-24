class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        bool r0=0, c0=0;
        for(int j=0; j<c; j++){
            if(!mat[0][j]){
                r0=1;  //first row will be 0;
                break;
            }
        }
        for(int i=0; i<r; i++){
            if(!mat[i][0]){
                c0=1; //first col will be 0;
                break;
            }
        }
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                if(!mat[i][j]){
                    mat[0][j]=0; //placeholders;
                    mat[i][0]=0;
                }
            }
        }
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                if(!mat[i][0] || !mat[0][j]){
                    mat[i][j]=0; //will be 0 if its corresponding row or col is 0;
                }
            }
        }
        if(r0){
            for(int j=0; j<c; j++){
                mat[0][j]=0;
            }
        }
        if(c0){
            for(int i=0; i<r; i++){
                mat[i][0]=0;
            }
        }
        return;
    }
};