class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(), cnt=n, l, r; //cuz single chars are palindromes;
        for(int i=0; i<n; i++){
            l=i-1, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                cnt++; 
                l--; r++;
            }
            l=i; r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                cnt++; 
                l--; r++;
            }
        }
        return cnt;
    }
};