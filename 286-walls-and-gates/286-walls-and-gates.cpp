class Solution {
public:
    void wallsAndGates(vector<vector<int>>& mat) {
        //bfs;
        //push all the gates;
        queue<pair<int, int>> q;
        int r=mat.size(), c=mat[0].size(), inf=-1+pow(2, 31), curr=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]==0){
                    q.push({i, j}); 
                }
            }
        }
        vector<pair<int, int>> dir={{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(q.size()){
            int n=q.size(); //all neighboring will be filled wid 1+curr;
            curr++;
            while(n--){
                int i=q.front().first, j=q.front().second;
                q.pop();
                for(int it=0; it<4; it++){
                    int ii=i+dir[it].first, jj=j+dir[it].second;
                    if(ii>=0 && ii<r && jj>=0 && jj<c && mat[ii][jj]==inf){
                        mat[ii][jj]=curr;
                        q.push({ii, jj}); //now we can go from here;
                    }
                }
            }
        }
        return;
    }
};