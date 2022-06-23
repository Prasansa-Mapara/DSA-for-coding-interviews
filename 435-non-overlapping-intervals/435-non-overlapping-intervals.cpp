class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int i=0, j=1, n=v.size(), cnt=0;
        while(j<n){
            if(v[j][0]<v[i][1]){ //remove an element;
                cnt++; 
                if(v[j][1]<v[i][1]){ //we want i to have the least end value;
                    i=j;
                }
            }
            else{
                i=j;
            }
            j++;
        }
        return cnt;
    }
};