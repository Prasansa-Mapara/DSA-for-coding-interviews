bool cmp(vector<int> x, vector<int> y){
    return x[0]<y[0];
}

class Solution {
public:
    vector<int> root;
    
    int find(int x){
        if(x==root[x]){
            return x;
        }
        return root[x]=find(root[x]);
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int time=0;
        //max time at which entire graph will be connected;
        //so first, sort it based on times;
        sort(logs.begin(), logs.end(), cmp);
        vector<int> rank(n, 1);
        root=rank;
        for(int i=0; i<n; i++){
            root[i]=i;
        }
        int tmp=n;
        for(auto l: logs){
            int rx=find(l[1]), ry=find(l[2]);
            if(rx==ry) continue;
            //else we'll have to connect them at given time;
            time=max(time, l[0]);
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
            tmp--;
        }
        if(tmp!=1) return -1;
        return time;
    }
};