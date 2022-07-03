class Solution {
public:
    int find(int x, vector<int> &root){
        if(x==root[x]){
            return x;
        }
        return x=find(root[x], root);
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        //no cycle and they should all be connected;
        int tmp=n;
        vector<int> root(n), rank(n, 1);
        for(int i=0; i<n; i++){
            root[i]=i;
        }
        for(auto i: edges){
            int rx=find(i[0], root), ry=find(i[1], root);
            if(rx==ry){ //since they're already in the same set, there's a cycle;
                return 0;
            }
            if(rank[rx]<rank[ry]){
                root[ry]=rx;
            }
            else if(rank[ry]<rank[rx]){
                root[rx]=ry;
            }
            else{
                root[ry]=rx;
                rank[rx]++;
            }
            tmp--;
        }
        if(tmp!=1) return 0;
        return 1;
   }
};