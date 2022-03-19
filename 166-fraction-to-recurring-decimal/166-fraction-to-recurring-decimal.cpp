class Solution {
public:
    string fractionToDecimal(int num, int den) {
        string ans="";
        long long int n=num, d=den;
        if((n<0 && d>0) || (n>0 && d<0)){
            if(n<0) n*=(-1);
            else if(d<0) d*=(-1);
            ans+="-";
        }
        ans+=to_string(n/d);
        if(!(n%d)) return ans;
        ans+=".";
        long long int rem=n%d;
        string res="";
        unordered_map<long long int, int> um;
        while(rem && um.find(rem)==um.end()){
            um[rem]=res.size();
            rem*=10;
            long long int frac=rem/d;
            res+=to_string(frac);
            rem%=d;
        }
        if(um.find(rem)!=um.end()){
            int x=um[rem];
            ans+=res.substr(0, x);
            ans+="("+res.substr(x)+")";
        }
        else if(!rem){
            ans+=res;
        }
        return ans;
    }
};