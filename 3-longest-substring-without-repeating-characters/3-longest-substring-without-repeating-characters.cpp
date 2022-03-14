class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n=s.size(), sol=0;
        unordered_set<char> hash;
        while(r<n){
            if(hash.find(s[r])!=hash.end()){ //char exists
                hash.erase(s[l]);
                l++;
            }
            else{ //char doesn't exist
                hash.insert(s[r]);
                sol=max(r-l+1, sol);
                r++;
            }
        }
        return sol;
    }
};