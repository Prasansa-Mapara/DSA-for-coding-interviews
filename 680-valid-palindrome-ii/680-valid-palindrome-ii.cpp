class Solution {
public:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i]==s[j]){
                i++; j--;
            }
            else return 0;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int n=s.size(), i=0, j=n-1;
        bool flag=0;
        while(i<j){
            if(s[i]==s[j]){
                i++; j--;
            }
            else{
                if(check(s, i+1, j) || check(s, i, j-1)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        return 1;
    }
};