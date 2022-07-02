class Solution {
public:
    vector<int> root;
    
    int find(int i){
        if(i==root[i]){
            return i;
        }
        return root[i]=find(root[i]);
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
                sol--; //since i have connected x and y by an edges now, 
                //number of connected components will reduce by 1;
                //ex: 1,2,3 -> conn=3
                //1-2, 3 -> conn=2;
            }
        }
        
        return sol;
    }
};