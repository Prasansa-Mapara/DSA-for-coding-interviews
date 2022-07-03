class Solution {
public:
    vector<int> root;
    
    int find(int x){
        if(x==root[x]){
            return x;
        }
        return root[x]=find(root[x]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //we can sort the strings that are in the same set;
        int n=s.size();
        vector<int> rank(n, 1);
        root=rank;
        for(int i=0; i<n; i++){
            root[i]=i;
        }
        for(auto p: pairs){
            int rx=find(p[0]), ry=find(p[1]);
            if(rx!=ry){
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
            }
        }
        unordered_map<int, vector<int>> hash;
        for(int i=0; i<n; i++){
            int ri=find(i);
            hash[ri].push_back(i);
        }
        for(auto i: hash){
            string tmp="";
            for(auto ind: i.second){
                tmp.push_back(s[ind]);
            }
            sort(tmp.begin(), tmp.end());
            for(int j=0; j<tmp.size(); j++){
                int ind=i.second[j];
                s[ind]=tmp[j];
            }
        }
        return s;
    }
};