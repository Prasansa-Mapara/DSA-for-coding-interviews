class Solution {
public:
    vector<int> root;
    
    int find(int i){
        if(i==root[i]){
            return i;
        }
        root[i]=find(root[i]);
        return root[i];
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        //do union find, then check for number of distinct roots;
        //tc: O(N);
        vector<int> rank(n, 1);
        root.resize(n);
        for(int i=0; i<n; i++){
            root[i]=i;
        }
        int sz=edges.size(), sol=n;
        for(int i=0; i<sz; i++){
            int x=edges[i][0], y=edges[i][1];
            int rootX=find(x), rootY=find(y);
            if(rootX!=rootY){ //if these vertices aren't already connected;
                if(rank[rootX]>rank[rootY]){
                    rank[rootX]+=rank[rootY];
                    root[rootY]=rootX;
                }
                else{
                    rank[rootY]+=rank[rootX];
                    root[rootX]=rootY;
                }
                sol--;
            }
        }
        
        return sol;
    }
};