#define pb push_back

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> a;
        a.pb({1});
        if(n==1) return a;
        a.pb({1, 1});
        if(n==2) return a;
        n-=2;
        while(n--){
            vector<int> x, prev=a[a.size()-1];
            
            x.pb(1);
            for(int i=0; i<prev.size()-1; i++){
                int y=prev[i]+prev[i+1];
                x.pb(y);
            }
            x.pb(1);
            a.pb(x);
        }
        return a;
    }
};