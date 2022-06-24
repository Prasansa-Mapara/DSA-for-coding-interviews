class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol(n+1, 0);
        //we know that x&(x-1) turns the last set bit to 0;
        //so, number of 1s in x, will be number of 1s in x&(x-1), +1;
        for(int i=1; i<=n; i++){
            sol[i]=sol[i&(i-1)]+1;
        }
        return sol;
    }
};