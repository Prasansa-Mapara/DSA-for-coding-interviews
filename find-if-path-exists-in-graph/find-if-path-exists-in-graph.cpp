class Solution {
public:
    vector<int> root;
    
    int find(int x){
        if(x==root[x]){
            return x;
        }
        return root[x]=find(root[x]);
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        //its connected components;
        //if in the end, source and dst have same root then return 1;
        vector<int> rank(n, 1);
        root=rank;
        for(int i=0; i<n; i++){
            root[i]=i;
        }
        for(auto e: edges){
            int rx=find(e[0]), ry=find(e[1]);
            if(rx!=ry){
                if(rank[rx]<rank[ry]){
                    root[rx]=ry;
                }
                else if(rank[rx]>rank[ry]){
                    root[ry]=rx;
                }
                else{
                    root[ry]=rx;
                    rank[rx]++;
                }
            }
        }
        int rs=find(src), rd=find(dst);
        if(rs==rd) return 1;
        return 0;
    }
};