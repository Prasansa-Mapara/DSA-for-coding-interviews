class Solution {
public:
    bool isValid(vector<vector<char>> &mat, int r, int c, int k){
        for(int i=0; i<9; i++){
            if(mat[r][i]==(char)k+'0'){
                return 0;
            }
            if(mat[i][c]==(char)k+'0'){
                return 0;
            }
            int x=3*(r/3), y=3*(c/3);
            for(int i=x; i<(x+3); i++){
                for(int j=y; j<(y+3); j++){
                    if(mat[i][j]==(char)k+'0'){
                        return 0;
                    }
                }
            }
            
        }
        return 1;
    }
    
    bool solve(vector<vector<char>>& mat){
        int r=-1, c=-1;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j]=='.'){
                    r=i; c=j;
                    break;
                }
            }
        }
        if(r==-1 && c==-1){
            return 1;
        }
        for(int k=1; k<=9; k++){
            if(isValid(mat, r, c, k)){
                mat[r][c]=(char)k+'0';
                if(solve(mat)){
                    return 1;
                }
                else{
                    mat[r][c]='.';
                }
            }
        }
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};