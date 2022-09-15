class Solution {
public:
    vector<vector<char>> mat;
    vector<vector<int>> dir={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    void dfs(int i, int j){
        int r=mat.size(), c=mat[0].size();
        if(i<0 || i>=r || j<0 || j>=c){
            return;
        }
        if(mat[i][j]=='0'){
            return;
        }
        mat[i][j]='0'; //marked as visited;
        for(auto curr: dir){
            int x=curr[0], y=curr[1];
            dfs(i+x, j+y);
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        mat=grid;
        int r=mat.size(), c=mat[0].size(), islands=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]=='1'){ //land
                    islands++;
                    dfs(i, j);
                }
            }
        }
        return islands;
    }
};

