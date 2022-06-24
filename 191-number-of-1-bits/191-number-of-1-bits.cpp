class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sol=0;
        while(n){
            sol+=n&1;
            n>>=1;
        }
        return sol;
    }
};