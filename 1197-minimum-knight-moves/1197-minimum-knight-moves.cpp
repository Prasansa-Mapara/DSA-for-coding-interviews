class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<pair<int, int>> dir;
        dir.push_back({1, 2}); dir.push_back({2, 1});
        dir.push_back({1, -2}); dir.push_back({2, -1});
        dir.push_back({-1, 2}); dir.push_back({-2, 1});
        dir.push_back({-1, -2}); dir.push_back({-2, -1});
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> vis(607, vector<bool>(607, 0));
        q.push({0, {0, 0}});
        
        while(q.size()){
            int steps=q.front().first; 
            int xx=q.front().second.first, yy=q.front().second.second;            
            q.pop();
            
            if(xx==x && yy==y){
                return steps;
            }
            else{
                for(int i=0; i<8; i++){
                    int xi=xx+dir[i].first+302, yi=yy+dir[i].second+302;
                    if(vis[xi][yi]==0){
                        vis[xi][yi]=1;
                        q.push({steps+1, {xi-302, yi-302}});
                    }
                }
            }
        }
        
        return -1;
    }
};