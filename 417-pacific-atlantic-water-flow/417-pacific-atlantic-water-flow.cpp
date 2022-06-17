class Solution {
public:
    void dfs(vector<vector<int>> &v, vector<vector<int>> &ocean, int i, int j){
        int r=v.size(), c=v[0].size(); 
        if(ocean[i][j]){
            return;
        }
        ocean[i][j]=1; //it can reach the ocean and its visited;
        
        if((i+1)<r && v[i+1][j]>=v[i][j]){
            dfs(v, ocean, i+1, j);
        }
        if((i-1)>=0 && v[i-1][j]>=v[i][j]){
            dfs(v, ocean, i-1, j);
        }
        if((j+1)<c && v[i][j+1]>=v[i][j]){
            dfs(v, ocean, i, j+1);
        }
        if((j-1)>=0 && v[i][j-1]>=v[i][j]){
            dfs(v, ocean, i, j-1);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int r=v.size(), c=v[0].size();
        //we know tht cells in first row n first col can reach pac ocean;
        //also, cells in last row n last col can reach atl ocean;
        vector<vector<int>> pac(r, vector<int>(c, 0)), atl=pac;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(j==0 || i==0){ //if this cell can reach pac, then check for its neighbors;
                    dfs(v, pac, i, j); 
                }
                if(i==(r-1) || j==(c-1)){ //if this cell can reach atl, then check for its neighbors;
                    dfs(v, atl, i, j);
                }
            }
        }
        
        vector<vector<int>> sol;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(pac[i][j] && atl[i][j]){
                    sol.push_back({i, j});
                }
            }
        }
        return sol;
    }
};