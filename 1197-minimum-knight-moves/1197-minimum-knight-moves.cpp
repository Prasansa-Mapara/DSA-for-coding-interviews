class Solution {
public:
    int minKnightMoves(int x, int y) {
        //will solve this using BFS;
        //since the solution will be similar for (x,y), (x,-y), (-x,y), (-x,-y), will reduce the solution space to the first quadrant;
        //when we'll reach the neighbourhood, it will take 2 steps, till then, if we start from target, 
        //will only have to move in (-1,-2) and (-2,-1), just to get closer to the origin;
        
        x=abs(x); y=abs(y);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {x, y}});
        set<pair<int, int>> vis;
        int sol=INT_MAX;
        
        while(q.size()){
            auto it=q.front();
            q.pop();
            int st=it.first, xx=it.second.first, yy=it.second.second;
            xx=abs(xx); yy=abs(yy);
            if(xx==0 && yy==0){
                return st;
            }
            else if((xx+yy)==2){ //in the neighbourhood;
                sol=min(sol, st+2); //cuz next elements in queue, might end up at (0,0);
            }
            else{
                if(vis.find({xx, yy})==vis.end()){
                    vis.insert({xx, yy});
                    q.push({st+1, {xx-2, yy-1}});
                    q.push({st+1, {xx-1, yy-2}}); //these 2 are the only steps we need to take to reach closer to the origin;
                }
            }
        }
        
        return sol;
    }
};