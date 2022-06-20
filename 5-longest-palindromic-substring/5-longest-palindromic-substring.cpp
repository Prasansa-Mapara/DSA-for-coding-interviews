class Solution {
public:
    string longestPalindrome(string s) {
        //if any substring is a palindrome, then if their front and back chars match, then tht new substring is also a palindrome;
        //so basically work around the center;
        int n=s.size(), ind=0, len=1;
        for(int i=1; i<n-1; i++){ //for subtrings of odd length;
            int l=i-1, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                int curr=r-l+1;
                if(curr>len){
                    ind=l; 
                    len=curr;
                }
                l--; r++; //keep expanding around the center;
            }
        }
        for(int i=0; i<n-1; i++){
            int l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                int curr=r-l+1;
                if(curr>len){
                    ind=l; 
                    len=curr;
                }
                l--; r++;
            }
        }
        return s.substr(ind, len);
    }
};