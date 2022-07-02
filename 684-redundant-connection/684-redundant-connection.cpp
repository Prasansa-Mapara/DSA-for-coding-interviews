class Solution {
public:
    
    int find(int curr, vector<int> root){
        if(curr==root[curr]){
            return curr;
        }
        root[curr]=find(root[curr], root); //cuz we want the main root; 
        //so will assign that main root to every node in btwn,
        //so in future, we can get it in O(1);
        return root[curr]; 
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //this is plain application of union find;
        //itearte through the edges, unionize those vertices,
        //if those vertices are already in the same set, then return ans;
        //here, simple dfs could also have done, but we want last edge, so union find's better way to do it;
        
        int n=edges.size();
        vector<int> root(n+1, 0), rank(n+1, 1);
        for(int i=1; i<=n; i++){
            root[i]=i;
        }
        for(int i=0; i<n; i++){
            int x=edges[i][0], y=edges[i][1];
            int rootX=find(x, root), rootY=find(y, root);
            if(rootX==rootY){ //they alreayd connected;
                return {x, y};
            }
            if(rank[rootX]>rank[rootY]){
                rank[rootX]+=rank[rootY];
                root[rootY]=rootX;
            }
            else{
                rank[rootY]+=rank[rootX];
                root[rootX]=rootY;
            }
        }
        return {};
    }
};