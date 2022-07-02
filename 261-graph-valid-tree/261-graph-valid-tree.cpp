class Solution {
public:
    vector<int> root;
    
    int find(int i){
        if(i==root[i]){
            return i;
        }
        return root[i]=find(root[i]);
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        //if theres a cycle then the tree's not valid;
        //this can be done by both union find and dfs;
        //also the entire tree's connected, so #connectedComponents=1;
        
        vector<int> rank(n, 1);
        root.resize(n);
        for(int i=0; i<n; i++){
            root[i]=i;
        }
        
        int conn=n;
        
        for(auto i: edges){
            int x=i[0], y=i[1];
            int rx=find(x), ry=find(y);
            if(rx==ry) return 0;
            else if(rank[rx]>rank[ry]){
                rank[rx]+=rank[ry];
                root[ry]=rx;
            }
            else{
                rank[ry]+=rank[rx];
                root[rx]=ry;
            }
            conn--;
        }
        
        if(conn==1) return 1;
        return 0;
    }
};