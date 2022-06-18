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
        while(q.size()){
            int n=q.size(); //all neighboring will be filled wid 1+curr;
            curr++;
            while(n--){
                int i=q.front().first, j=q.front().second;
                q.pop();
                if(i+1<r && mat[i+1][j]==inf){
                    mat[i+1][j]=curr;
                    q.push({i+1, j}); //now we can go from here;
                }
                if(j+1<c && mat[i][j+1]==inf){
                    mat[i][j+1]=curr;
                    q.push({i, j+1});
                }
                if(i-1>=0 && mat[i-1][j]==inf){
                    mat[i-1][j]=curr;
                    q.push({i-1, j});
                }
                if(j-1>=0 && mat[i][j-1]==inf){
                    mat[i][j-1]=curr;
                    q.push({i, j-1});
                }
            }
        }
        return;
    }
};