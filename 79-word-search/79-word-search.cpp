class Solution {
public:
    vector<vector<char>> mat;
    string s;
    bool sol=0;
    
    void dfs(int x, int y, int ind){
        int n=s.size(), r=mat.size(), c=mat[0].size();
        if(ind>=n){
            sol=1;
            return;
        }
        if(x<0 || y<0 || x>=r || y>=c || mat[x][y]=='#' || mat[x][y]!=s[ind]){
            return;
        }
        char ch=mat[x][y];
        mat[x][y]='#';
        dfs(x+1, y, ind+1);
        dfs(x-1, y, ind+1);
        dfs(x, y+1, ind+1);
        dfs(x, y-1, ind+1);
        mat[x][y]=ch;
    }
    
    //TC: O(r*c*3^l);
    //3^l cuz for each index, we'll be visiting in three other directions;
    
    bool exist(vector<vector<char>>& board, string word) {
        mat=board; 
        s=word;
        int r=mat.size(), c=mat[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                dfs(i, j, 0);
                if(sol){
                    return 1;
                }
            }
        }
        return sol;
    }
};