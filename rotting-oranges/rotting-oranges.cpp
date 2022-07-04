#define pii pair<int, int>
#define ff first
#define ss second

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        queue<pii> q;
        int fresh=0, r=mat.size(), c=mat[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]==2){
                    q.push({i, j});
                }
                else if(mat[i][j]==1){
                    fresh++;
                }
            }
        }
        int mins=0;
        vector<pii> dir={{0,1},{1,0},{-1,0},{0,-1}};
        
        while(q.size()){
            int n=q.size();
            if(!fresh) return mins;
            while(n--){
                int x=q.front().ff, y=q.front().ss;
                q.pop();
                for(int i=0; i<4; i++){
                    int xx=x+dir[i].ff, yy=y+dir[i].ss;
                    if(xx>=0 && xx<r && yy>=0 && yy<c && mat[xx][yy]==1){
                        mat[xx][yy]=2;
                        q.push({xx, yy});
                        fresh--;
                    }
                }
            }
            mins++;
        }
        
        if(fresh) return -1;
        return mins;
    }
};