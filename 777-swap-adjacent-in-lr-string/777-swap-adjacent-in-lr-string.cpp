#define pb push_back
class Solution {
public:
    bool canTransform(string s, string e) {
        int n=s.size(), i=0, j=0;
        string a, b;
        for(i=0; i<n; i++){
            if(s[i]!='X') a.pb(s[i]);
            if(e[i]!='X') b.pb(e[i]);
        }
        if(a!=b) return 0;
        
        i=0; j=0;
        while(i<n && j<n){
            if(s[i]=='X') i++;
            else if(e[j]=='X') j++;
            else if(s[i]=='L' && i<j) return 0;
            else if(s[i]=='R' && i>j) return 0;
            else{
                i++; j++;
            }
        }
        
        return 1;
    }
};