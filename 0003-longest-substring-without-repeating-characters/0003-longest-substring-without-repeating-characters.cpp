class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*int n=s.size(), l=0, r=l+1, sol=1; //because each element is a substring
        if(n==0) return 0;
        unordered_map<char, int> hash;
        hash[s[l]]=l;
        while(r<n){
            if(hash.find(s[r])!=hash.end()){
                l=max(l, hash[s[r]]+1); //current character (s[r]) was first found at hash[s[r]] index;
                //so we'll move one step ahead; now [l,r] won't have any duplicate characters;
            }
            hash[s[r]]=r;
            r++; 
            sol=max(sol, r-l); 
        }
        return sol;*/
        
        int n=s.size();
        if(n<=1) return n;
        
        unordered_map<char, int> hash;
        hash[s[0]]=0;
        int l=0, r=1, sol=1;
        
        //pwwpew
        
        while(r<n){
            if(hash.find(s[r])==hash.end()){
                hash[s[r]]=r;
            }
            else{
                l=max(l, hash[s[r]]+1); //cuz we cant include that index;
                hash[s[r]]=r;
            }
            r++;
            sol=max(sol, r-l);
        }
        
        return sol;
    }
};