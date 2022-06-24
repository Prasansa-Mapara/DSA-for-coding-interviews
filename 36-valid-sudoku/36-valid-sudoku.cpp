class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        //keep a hash for each row, each col, and each box;
        vector<unordered_set<char>> row(9), col(9), box(9);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j]=='.'){
                    continue;
                }
                char c=mat[i][j];
                if(row[i].find(c)!=row[i].end()){
                    return 0;
                }
                else{
                    row[i].insert(c);
                }
                if(col[j].find(c)!=col[i].end()){
                    return 0;
                }
                else{
                    col[j].insert(c);
                }
                int x=(i/3)*3, y=j/3;
                if(box[x+y].find(c)!=box[x+y].end()){
                    return 0;
                }
                else{
                    box[x+y].insert(c);
                }
            }
        }
        return 1;
    }
};