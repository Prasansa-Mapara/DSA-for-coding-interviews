class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sol=1, n=s.size();
        if(n==0) return 0;
        int l=0, r=0; 
        unordered_set<char> hash;
        hash.insert(s[l]);
        r=l+1;
        while(r<n){
            if(hash.find(s[r])==hash.end()){
                hash.insert(s[r]);
                sol=max(sol, r-l+1);
                r++;
            }
            else{
                hash.erase(hash.find(s[l]));
                l++;
            }
        }
        return sol;
    }
};