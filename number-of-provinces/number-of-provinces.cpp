class Solution {
public:
    int find(int x, vector<int> &root){
        if(x==root[x]){
            return x;
        }
        return root[x]=find(root[x], root);
    }
    
    int findCircleNum(vector<vector<int>>& isCon) {
        //connected components;
        //can be solved using dfs, or dsu;
        int n=isCon.size(), sol=n;
        vector<int> rank(n, 1), root(n);
        for(int i=0; i<n; i++){
            root[i]=i;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isCon[i][j]){ //provinces i and j are connected, so do union;
                    int ri=find(i, root), rj=find(j, root);
                    if(ri==rj) continue; //already in the same set;
                    if(rank[ri]>rank[rj]){
                        root[rj]=ri;
                    }
                    else if(rank[ri]<rank[rj]){
                        root[ri]=rj;
                    }
                    else{
                        root[rj]=ri;
                        rank[ri]++;
                    }
                    //now we've put these provinces in the same set, so conn will reduce by 1;
                    sol--;
                }
            }
        }
        return sol;
    }
};