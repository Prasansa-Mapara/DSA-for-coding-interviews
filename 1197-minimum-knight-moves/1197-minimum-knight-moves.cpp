class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<pair<int, int>> dir;
        if(x<0) x=-x;
        if(y<0) y=-y;
        dir.push_back({-1, -2}); dir.push_back({-2, -1});
        
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> vis;
        q.push({0, {x, y}});
        int sol=INT_MAX;
        
        while(q.size()){
            int steps=q.front().first; 
            int xx=q.front().second.first, yy=q.front().second.second;   
            xx=abs(xx); yy=abs(yy);
            q.pop();
            
            if((xx==0 && yy==0)){
                return steps;
            }
            else if((xx+yy)==2){
                sol=min(sol, steps+2);
            }
            else{
                for(int i=0; i<2; i++){
                    int xi=xx+dir[i].first, yi=yy+dir[i].second;
                    xi=abs(xi); yi=abs(yi);
                    if(vis.find({xi, yi})==vis.end()){
                        vis.insert({xi, yi});
                        q.push({steps+1, {xi, yi}});
                    }
                }
            }
        }
        
        return sol;
    }
};