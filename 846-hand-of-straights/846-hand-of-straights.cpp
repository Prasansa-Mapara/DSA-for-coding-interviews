#define ss second
#define ff first

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz) {
        int n=hand.size(); 
        if(n%sz) return 0;
        map<int, int> hash;

        for(auto i: hand){
            hash[i]++;
        }
        
        while(hash.size()){
            auto i=hash.begin();
            if(i->ss){ //if this card is present, then we want sz consecutive cards;
                int curr=i->ff;
                for(int j=0; j<sz; j++){
                    if(hash[curr+j]>0){
                        hash[curr+j]--;
                        if(hash[curr+j]==0){
                            hash.erase(hash.find(curr+j));
                        }
                    }
                    else{
                        return 0;
                    }
                }
            }
        }  
        
        return 1;
    }
};