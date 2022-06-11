class Solution {
public:
    int orangesRotting(vector<vector<int>> mat) {
        int r=mat.size(), c=mat[0].size();
        queue<pair<int, int>> q;
        int fresh=0;
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
        if(fresh==0) return 0;
        int mins=0;
        while(q.size()){
            int n=q.size();
            mins++;
            while(n--){
                int i=q.front().first, j=q.front().second;
                q.pop();
                if((i+1)<r && mat[i+1][j]==1){
                    fresh--;
                    mat[i+1][j]=2;
                    q.push({i+1, j});
                }
                if((i-1)>=0 && mat[i-1][j]==1){
                    fresh--;
                    mat[i-1][j]=2;
                    q.push({i-1, j});
                }
                if((j+1)<c && mat[i][j+1]==1){
                    fresh--;
                    mat[i][j+1]=2;
                    q.push({i, j+1});
                }
                if((j-1)>=0 && mat[i][j-1]==1){
                    fresh--;
                    mat[i][j-1]=2;
                    q.push({i, j-1});
                }
                if(fresh==0) return mins;
            }
        }
        return -1;
    }
};