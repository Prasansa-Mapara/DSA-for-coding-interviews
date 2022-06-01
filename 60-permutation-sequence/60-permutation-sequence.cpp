class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1);
        fact[0]=1;
        for(int i=1; i<=n; i++){
            fact[i]=i*fact[i-1]; //store the factorials beforehand;
        }
        string s, sol;
        for(int i=1; i<=n; i++){
            s+=to_string(i);
        }
        while(n){
            int ind=(k/fact[n-1]); //this will be the table number that we'll have to consider;  
            if((k%fact[n-1])==0) ind--; //boundary check;
            sol.push_back(s[ind]); 
            s.erase(s.begin()+ind); 
            k-=(fact[n-1]*(ind));  //here ind will be table number in 0 based indexing, so there'll be ind number of tables before it, we need to discared those, so multiply it with the table size that is fact[n-1]
            n--; //so now, n will be 1 less;
        }
        return sol;
    }
};