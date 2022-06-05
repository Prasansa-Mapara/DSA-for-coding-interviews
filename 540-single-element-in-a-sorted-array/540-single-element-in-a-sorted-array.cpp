class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n=v.size(), lo=0, hi=n-1; //n=7
        while(lo<hi){ //lo=4, hi=6
            int mid=lo+(hi-lo)/2; //5
            if((mid-1)>=0 && v[mid]==v[mid-1]){
                int a=mid-lo-1, b=hi-mid; //a=2, b=3
                if(a%2){ //left side has odd number of elements
                    hi=mid-2;
                }
                else{
                    lo=mid+1; //4
                }
            }
            else if((mid+1)<n && v[mid]==v[mid+1]){
                int a=mid-lo, b=hi-mid-1;
                if(a%2){
                    hi=mid-1;
                }
                else{
                    lo=mid+2;
                }
            }
            else{
                return v[mid];
            }
        }
        return v[hi];
    }
};