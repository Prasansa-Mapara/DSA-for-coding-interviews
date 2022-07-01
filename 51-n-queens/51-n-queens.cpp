class Solution {
public:
    vector<vector<string>> sol;
    vector<string> mat;
    int n;
    
    bool isPossible(vector<string> &mat, int r, int c){
        for(int j=0; j<c; j++){
            if(mat[r][j]=='Q'){ //there's a queen in the same row;
                return 0;
            }
        }
        for(int i=0; i<r; i++){
            if(mat[i][c]=='Q'){
                return 0;
            }
        }
        for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
            if(mat[i][j]=='Q'){
                return 0;
            }
        }
        for(int i=r-1, j=c+1; i>=0 && j<n; i--, j++){
            if(mat[i][j]=='Q'){
                return 0;
            }
        }
        return 1;
    }
    
    void solve(int r){
        if(r==n){
            sol.push_back(mat);
            return;
        }
        for(int c=0; c<n; c++){
            if(isPossible(mat, r, c)){
                mat[r][c]='Q';
                solve(r+1);
                mat[r][c]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int nn) {
        n=nn;
        for(int i=0; i<n; i++){
            string tmp="";
            for(int j=0; j<n; j++){
                tmp.push_back('.');
            }
            mat.push_back(tmp);
        }
        solve(0);
        return sol;
    }
};