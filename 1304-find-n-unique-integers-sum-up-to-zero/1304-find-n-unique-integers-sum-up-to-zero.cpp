#define pb push_back

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        int i=1;
        while(n>1){
            v.pb(-i);
            v.pb(i);
            n-=2;
            i++;
        }
        if(n) v.pb(0);
        return v;
    }
};