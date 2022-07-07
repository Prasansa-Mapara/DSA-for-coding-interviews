class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> hash;
        int n=stones.size();
        for(int i=0; i<n; i++){
            hash[stones[i]]={};
        }
        hash[stones[0]].insert(0); //pos->set of jump sizes to reach that pos;
        for(int i=0; i<n; i++){
            int curr=stones[i];
            for(auto j: hash[stones[i]]){
                for(int jump=j-1; jump<=j+1; jump++){
                    if(jump<1) continue;
                    if(hash.find(curr+jump)!=hash.end()){
                        hash[curr+jump].insert(jump);
                        if(curr+jump==stones[n-1]) return 1;
                    }
                }
            }
        }
        
        return hash[stones[n-1]].size()>0;
    }
};