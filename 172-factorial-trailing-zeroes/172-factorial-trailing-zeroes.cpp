class Solution {
public:
    int trailingZeroes(int n) {
        //these are cuz of 2*5, since we'll always have more 2's than 5's
        //we'll count the total occurence of 5's
        int sol=0;
        for(int i=1; pow(5, i)<=n; i++){
            sol+=n/(pow(5, i));
        }
        return sol;
    }
};