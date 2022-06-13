class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(auto c: s){
            if((c>='a' && c<='z') || (c>='0' && c<='9')){
                tmp.push_back(c);
            }
        }
        cout<<tmp<<endl;
        string tmp2=tmp;
        reverse(tmp.begin(), tmp.end());
        if(tmp==tmp2) return 1;
        return 0;
    }
};