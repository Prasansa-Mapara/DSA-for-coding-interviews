class Solution {
public:
    
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        if(N==0) return (double)1;
        else if(N==1) return x;
        double y=myPow(x, N/2), ans=1;
        if(N%2){
            ans*=x;
        }
        ans*=y*y;
        return ans;
    }
};