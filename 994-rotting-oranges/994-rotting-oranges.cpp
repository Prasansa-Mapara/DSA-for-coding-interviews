class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        //we doing bfs here;
        queue<pair<int, int>> q; //it'll we store coordinates;
        int r=mat.size(), c=mat[0].size(), fresh=0, mins=0;
        //push all rotten oranges to the queue, cuz in first min, they will all convert thier neighboring fresh oranges into rotten;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]==1) fresh++;
                else if(mat[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        if(!fresh) return 0;
        while(q.size()){
            int n=q.size();
            mins++;
            while(n--){
                int i=q.front().first, j=q.front().second;
                q.pop();
                //push all fresh oranges adjacent to it, as now they are rotten;
                if(i+1<r && mat[i+1][j]==1){
                    fresh--; //now its rotten;
                    mat[i+1][j]=2;
                    q.push({i+1, j});
                }
                if(i-1>=0 && mat[i-1][j]==1){
                    fresh--; 
                    mat[i-1][j]=2;
                    q.push({i-1, j});
                }
                if(j+1<c && mat[i][j+1]==1){
                    fresh--;
                    mat[i][j+1]=2;
                    q.push({i, j+1});
                }
                if(j-1>=0 && mat[i][j-1]==1){
                    fresh--;
                    mat[i][j-1]=2;
                    q.push({i, j-1});
                }
                if(!fresh){
                    return mins;
                }
            }
        }
        if(fresh){ //if still there are any fresh oranges left, then return -1;
            return -1;
        }
        return mins;
    }
};