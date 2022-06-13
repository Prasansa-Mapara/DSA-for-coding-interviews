class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(i<j){
            if(isalnum(s[i]) && isalnum(s[j])){
                if(s[i]==s[j]){
                    i++; j--;
                }
                else{
                    return 0;
                }
            }
            if(!isalnum(s[i])){
                i++;
            }
            if(!isalnum(s[j])){
                j--;
            }
        }
        return 1;
    }
};