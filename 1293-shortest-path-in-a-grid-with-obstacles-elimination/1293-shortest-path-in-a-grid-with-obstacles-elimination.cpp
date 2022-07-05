#define ff first
#define ss second

class Solution {
public:
    vector<pair<int, int>> dir={{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    int shortestPath(vector<vector<int>>& mat, int k) {
        int r=mat.size(), c=mat[0].size();
        queue<pair<int, pair<int, int>>> q;
        if(mat[0][0]){
            if(k>=1) k--;
            else return -1;
        }
        
        q.push({k, {0, 0}});
        int steps=0;
        vector<vector<int>> vis(r, vector<int>(c, -1));
        
        while(q.size()){
            int n=q.size();
            
            while(n--){
                int curr=q.front().ff, x=q.front().ss.ff, y=q.front().ss.ss;
                if(x==r-1 && y==c-1){
                    return steps;
                }
                q.pop();
                for(int i=0; i<4; i++){
                    int xx=x+dir[i].ff, yy=y+dir[i].ss, kk=curr;
                    if(xx>=0 && xx<r && yy>=0 && yy<c){
                        if(mat[xx][yy]){ //if curr cell has an obstacle;
                            kk--; 
                            if(kk<0) continue;
                        }
                        if(vis[xx][yy]==-1 || vis[xx][yy]<kk){ //if not visited, or previous one had less saves;
                            vis[xx][yy]=kk;
                            q.push({kk, {xx, yy}});
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};