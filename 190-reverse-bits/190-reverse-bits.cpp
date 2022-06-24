class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sol=0;
        int j=0;
        for(int i=31; i>=0; i--){
            int x=n&1;
            n>>=1;
            sol+=x<<i;
        }
        return sol;
    }
};