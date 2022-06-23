class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n=v.size(), prev=0, curr=1, cnt=0;
        sort(v.begin(), v.end());
        while(curr<n){
            if(v[curr][0]>=v[prev][1]){ //it's at a perfect pos;
                prev=curr;
            }
            else{
                cnt++; //gotta remove this element;
                if(v[curr][1]<v[prev][1]){ //prev will have least ending value;
                    prev=curr;
                }
            }
            curr++;
        }
        return cnt;
    }
};