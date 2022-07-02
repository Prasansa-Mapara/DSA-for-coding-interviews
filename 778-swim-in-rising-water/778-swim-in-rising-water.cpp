#define ppi pair<int, pair<int, int>>
#define ff first
#define ss second

class Solution {
public:
    int swimInWater(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        //we want least time;
        //can travel from cell x, to cell y at time max(mat[x], mat[y]);
        //since we want min time, we can maintain a min heap, and traverse in a bfs manner;
        //pq will have {time, {x, y}};
        
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        pq.push({mat[0][0], {0, 0}});
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        
        vector<vector<bool>> vis(r, vector<bool>(c, 0));
        vis[0][0]=1;
        
        while(pq.size()){
            int time=pq.top().ff, x=pq.top().ss.ff, y=pq.top().ss.ss;
            pq.pop();
            if(x==r-1 && y==c-1) return time; //cuz it will be the min time, 
            //since we've a min heap;
            for(int i=0; i<4; i++){ //bfs traversal;
                int xx=x+dir[i][0], yy=y+dir[i][1];
                if(xx>=0 && yy>=0 && xx<r && yy<c && !vis[xx][yy]){ //if we've seen this cell before, then
                    //at that time, time would've been minimum, since we are always taking nodes that have 
                    //minimum time; so no need to store this one;
                    vis[xx][yy]=1;
                    if(xx==r-1 && yy==c-1){
                        return max(time, mat[xx][yy]); //as we can swim at time that's max of both;
                    }
                    pq.push({max(time, mat[xx][yy]), {xx, yy}});
                }
            }          
        }
        
        return 0;
    }
};