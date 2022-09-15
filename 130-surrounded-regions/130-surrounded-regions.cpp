class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        
        if(i<0 || i>=r || j<0 || j>=c || mat[i][j]=='X' || mat[i][j]=='p') 
            return;
        
        
        mat[i][j] = 'p';
        
        dfs(i,j+1,mat);
        dfs(i+1,j,mat);
        dfs(i-1,j,mat);
        dfs(i,j-1,mat);
        
        return;
    }
    
    void solve(vector<vector<char>>& board) 
    {
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0 || i== r-1 || j==0 || j==c-1)
                 {
                    if(board[i][j]=='O')
                    dfs(i,j,board);
                }
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='p')
                    board[i][j]='O';
            }
        }
        
        return;
    }
};