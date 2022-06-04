class Solution {
public:
    vector<vector<string>> sol;
    
    bool isPossible(int c, int n, vector<string> &tmp, int r){
        for(int i=0; i<r; i++){
            if(tmp[i][c]=='Q') return false;
        }
        for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
            if(tmp[i][j]=='Q'){
                return false;
            }
        }
        for(int i=r-1, j=c+1; i>=0 && j<n; i--, j++){
            if(tmp[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<string> tmp, int n, int ind){
        if(ind==n){
            sol.push_back(tmp);
            return;
        }
        for(int i=0; i<n; i++){
            if(isPossible(i, n, tmp, ind)){
                tmp[ind][i]='Q';
                solve(tmp, n, ind+1);
                tmp[ind][i]='.';
            } 
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s;
        vector<string> tmp;
        for(int i=0; i<n; i++) s+=".";
        for(int i=0; i<n; i++) tmp.push_back(s);
        solve(tmp, n, 0);
        return sol;
    }
};