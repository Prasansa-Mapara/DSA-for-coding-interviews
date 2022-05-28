class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(), sol=1, i=0;
        if(n==0) return 0; //if there's no char then it cant repeat;
        unordered_map<char, int> hash;
        hash[s[0]]=0;
        for(int j=1; j<n; j++){ 
            if(hash.find(s[j])!=hash.end()){
                i=max(i, hash[s[j]]+1); //if that char is found before, then i will be upated; consider tc "abba", for max;
            }
            hash[s[j]]=j; //update char to curr location;
            sol=max(sol, j-i+1);
        }
        return sol;
    }
};