#define ff first

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz) {
        map<int, int> hash;
        for(auto i: hand){
            hash[i]++;
        }
        while(hash.size()){
            int curr=hash.begin()->ff;
            for(int i=0; i<sz; i++){
                if(hash[curr+i]==0) return 0; //cuz this element isn't present;
                else{
                    hash[curr+i]--;
                    if(hash[curr+i]==0){
                        hash.erase(hash.find(curr+i));
                    }
                }
            }
        }
        return 1;
    }
};