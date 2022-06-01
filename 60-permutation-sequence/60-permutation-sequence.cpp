class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1);
        fact[0]=1;
        for(int i=1; i<=n; i++){
            fact[i]=i*fact[i-1];
        }
        string s, sol;
        for(int i=1; i<=n; i++){
            s+=to_string(i);
        }
        while(n){
            int ind=(k/fact[n-1]);   
            if((k%fact[n-1])==0) ind--;
            sol.push_back(s[ind]); 
            s.erase(s.begin()+ind); 
            k-=(fact[n-1]*(ind)); 
            n--;
        }
        return sol;
    }
};