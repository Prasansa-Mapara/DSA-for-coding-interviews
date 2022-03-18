class Solution {
public:
    int trailingZeroes(int n) {
        //zeroes is a result of 2*5, 
        //2 to bhar bharke honge, so we need total number of fives;
        //25! -> 25*..*20*..*15*..*10*..*5*..*1
        
        int ans=0;
        for(int i=1; pow(5, i)<=n; i++){
            ans+=n/pow(5, i);
        }
        return ans;
    }
};