class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 ) return (double) 1;
        else if(n==1) return x;
        else if(n==-1) return 1/x;
        double a=myPow(x, n/2), sol=1;
        if(n>0 && n%2){
            sol=x;
        }
        else if(n<0 && abs(n)%2){
            sol=1/x;
        }
        sol*=a*a;
        return sol;
    }
};