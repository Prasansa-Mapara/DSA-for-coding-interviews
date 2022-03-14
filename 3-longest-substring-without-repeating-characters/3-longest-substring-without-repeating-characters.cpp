class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, sol=0, n=s.size();
        unordered_map<char, int> hash;
        while(r<n){
            while(hash[s[r]]){
                hash[s[l]]--;
                l++;
            }
            hash[s[r]]++;
            sol=max(sol, r-l+1);
            r++;
        }
        return sol;
    }
};