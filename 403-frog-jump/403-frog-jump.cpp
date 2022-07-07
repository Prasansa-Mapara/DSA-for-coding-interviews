class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> hash;
        int n=stones.size();
        for(auto i: stones){
            hash[i]={};
        }
        hash[stones[0]].insert(0); //0 jumps to reach 1st stone;
        
        for(int i=0; i<n; i++){
            int pos=stones[i];
            for(auto j: hash[pos]){ //j is number of jumps needed to reach pos;
                for(int jump=j-1; jump<=j+1; jump++){
                    if(jump<1) continue; //staying at same pos or going down;
                    int nextPos=pos+jump;
                    if(nextPos==stones[n-1]) return 1;
                    if(hash.find(nextPos)!=hash.end()){ //if next pos is a valid pos;
                        hash[nextPos].insert(jump);
                    }
                }
            }
        }
        
        return 0;
    }
};