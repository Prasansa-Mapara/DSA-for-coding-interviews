#define pii pair<int, int>
#define ff first
#define ss second

class Solution {
public:
    vector<pii> dir={{1,0},{0,1},{1,1},{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int sol=1;
        int r=mat.size(), c=mat[0].size();
        queue<pii> q;
        q.push({0,0});
        if(mat[0][0]==1) return -1;
        mat[0][0]=1;
        while(q.size()){
            int n=q.size();
            while(n--){
                int x=q.front().ff, y=q.front().ss;
                q.pop();
                if(x==r-1 && y==c-1) return sol;
                for(int i=0; i<8; i++){
                    int xx=x+dir[i].ff, yy=y+dir[i].ss;
                    if(xx>=0 && xx<r && yy>=0 && yy<c && !mat[xx][yy]){
                        q.push({xx, yy});
                        mat[xx][yy]=1;
                    }
                }
            }
            sol++;
        }
        return -1;
    }
};