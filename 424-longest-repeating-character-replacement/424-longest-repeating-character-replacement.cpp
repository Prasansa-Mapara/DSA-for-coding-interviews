class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r, n=s.size(), cnt=0, sol=0;
        unordered_map<char, int> hash;
        for(int r=0; r<n; r++){
            hash[s[r]]++;
            cnt=max(cnt, hash[s[r]]); //cnt will be the max frequency of an element in thsi window; 
            int x=(r-l+1)-cnt; //num of chars to replace in this window will be total window size- number of characters that appear most frequently; 
            while(x>k){
                hash[s[l]]--;
                l++;
                x=(r-l+1)-cnt; 
            }
            if(x<=k){
                sol=max(sol, r-l+1);
            }
        }
        return sol;
    }
};