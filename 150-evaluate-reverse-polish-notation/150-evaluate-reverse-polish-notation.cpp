#define ll long long

class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<ll> num; 
        ll n=v.size();
        for(ll i=0; i<n; i++){
            if(v[i]!="+" && v[i]!="-" && v[i]!="*" && v[i]!="/"){
                num.push(stol(v[i]));
            }
            else{
                ll a=num.top(); num.pop();
                ll b=num.top(); num.pop();
                if(v[i]=="+") num.push(a+b);
                else if(v[i]=="*") num.push(a*b);
                else if(v[i]=="-") num.push(b-a);
                else num.push(b/a);
            }
        }
        return (int)num.top();
    }
};