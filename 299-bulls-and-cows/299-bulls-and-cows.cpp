class Solution {
public:
    string getHint(string sec, string gs) {
        int n=gs.size(), x=0, y=0;
        unordered_map<char, int> s, g;
        for(int i=0; i<n; i++){
            if(sec[i]==gs[i]) x++;
            else{
                if(g[sec[i]]>0){ //if it was seen before in guess
                    g[sec[i]]--;
                    y++;
                }
                else{
                    s[sec[i]]++;
                }
                if(s[gs[i]]>0){ //if it was seen before in secret
                    s[gs[i]]--;
                    y++;
                }
                else{
                    g[gs[i]]++;
                }
            }
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};