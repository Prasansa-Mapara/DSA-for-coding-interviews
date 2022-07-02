class Solution {
public:
    int findRoot(int i, vector<int> root){
        if(i==root[i]){
            return i;
        }
        return root[i]=findRoot(root[i], root);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> root(n+1, 0), rank(n+1, 1);
        for(int i=1; i<=n; i++){
            root[i]=i; //initially each set's disjoint;
        }
        for(int i=0; i<n; i++){
            int x=edges[i][0], y=edges[i][1];
            int rootX=findRoot(x, root), rootY=findRoot(y, root);
            if(rootX==rootY){
                return {x, y};
            }
            else if(rank[rootX]>rank[rootY]){ //rootX has more power;
                rank[rootX]+=rank[rootY];
                root[rootY]=rootX;
            }
            else{ //rootY has more power
                rank[rootY]+=rootX;
                root[rootX]=rootY;
            }
        }
        return {};
    }
};