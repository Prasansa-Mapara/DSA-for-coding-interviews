#define pii pair<int, int>

class Solution {
public:
    int swimInWater(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        //here, since we know that we can reach the last cell in the time (*max_element(mat.begin(), mat.end()));
        //so, one way is to do binary search, while doing bfs traversal ofc;
        //with that approach, tc will be O(logn*n^2), n^2 fro bfs or dfs;
         
        //another way is to do pq+bfs;
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        pq.push({mat[0][0], {0, 0}});
        vector<vector<bool>> vis(r, vector<bool>(c, 0));
        vis[0][0]=1;
        vector<vector<int>> dir={{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while(pq.size()){
            int time=pq.top().first, x=pq.top().second.first, y=pq.top().second.second;
            if(x==(r-1) && y==(c-1)) return time;
            pq.pop();
            for(int i=0; i<4; i++){
                int xx=x+dir[i][0], yy=y+dir[i][1];
                if(xx>=0 && xx<r && yy>=0 && yy<c && !vis[xx][yy]){
                    if(xx==r-1 && yy==c-1){
                        return max(time, mat[xx][yy]);
                    }
                    pq.push({max(time, mat[xx][yy]), {xx, yy}});
                    vis[xx][yy]=1;
                }
            }
        }
        
        return 0;
    }
};