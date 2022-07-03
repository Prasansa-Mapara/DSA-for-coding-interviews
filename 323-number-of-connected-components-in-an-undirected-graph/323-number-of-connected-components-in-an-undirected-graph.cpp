class Solution {
public:
    vector<int> root;
    
    int find(int x){
        if(x==root[x]){
            return x;
        }
        return root[x]=find(root[x]);
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> rank(n, 1);
        root=rank;
        for(int i=0; i<n; i++){
            root[i]=i;
        }
        int sol=n;
        for(auto e: edges){
            int rx=find(e[0]), ry=find(e[1]);
            if(rx==ry) continue;
            
            if(rank[rx]>rank[ry]){
                root[ry]=rx;
            }
            else if(rank[rx]<rank[ry]){
                root[rx]=ry;
            }
            else{
                root[ry]=rx;
                rank[rx]++;
            }
            sol--;
        }
        return sol;
    }
};