#define pii pair<int, int>
#define ppi pair<int, pii> 
#define ff first
#define ss second;

class Solution {
public:
    vector<pair<int, int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    
    int minimumEffortPath(vector<vector<int>>& mat) {
        //min effort, i.e. shortest path;
        //single source, no negative, so dijkstra's;
        //it'll be simpler using dijkstra's than bellman ford;
        
        int r=mat.size(), c=mat[0].size();
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq; //, vector<ppi>, greater<ppi>> pq; //effort->{x,y};
        pq.push({0, {0, 0}});
        vector<vector<bool>> vis(r, vector<bool>(c, 0));
        
        while(pq.size()){
            int effort=pq.top().ff;
            auto i=pq.top().ss;
            int x=i.ff, y=i.ss;
            pq.pop();
            if(x==r-1 && y==c-1) return effort;
            if(vis[x][y]) continue;
            vis[x][y]=1;
            
            for(auto d: dir){
                int xx=x+d.ff, yy=y+d.ss;
                if(xx>=0 && yy>=0 && xx<r && yy<c && !vis[xx][yy]){
                    pq.push({max(effort, abs(mat[xx][yy]-mat[x][y])), {xx, yy}});
                }
            }
        }
        
        return -1;
    }
};