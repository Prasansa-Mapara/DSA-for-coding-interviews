class Solution {
public:
    double solve(double x, int n){
        if(n==0) return (double)1;
        else if(n==1) return x;
        else{
            double ans=1, y=solve(x, n/2);
            if(n%2){
                ans*=x;
            }
            ans*=y*y;
            return ans;
        }
    }
    
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        double y=solve(x, N/2), ans=1;
        if(N%2){
            ans*=x;
        }
        ans*=y*y;
        return ans;
    }
};