#define ff first
#define ss second

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& v) {
        unordered_map<int, set<int>> hash;
        int sol=0;
        for(auto i: v){
            int x=i[1], y=i[0];
            if(x>=2 && x<=5) hash[y].insert(0);
            if(x>=4 && x<=7) hash[y].insert(1);
            if(x>=6 && x<=9) hash[y].insert(2);
        }
        int tmp=n-hash.size();
        sol+=tmp*2; //for all unoccupied rows, we can have 2 families;
        for(auto i: hash){
            int r=i.ff;
            set<int> s=i.ss;
            if(s.find(0)==s.end()){
                s.insert(1);
            }
            if(s.find(2)==s.end()){
                s.insert(1);
            }
            if(s.find(1)==s.end()){
                s.insert(0); s.insert(2);
            }
            sol+=3-s.size();
        }
        return sol;
    }
};