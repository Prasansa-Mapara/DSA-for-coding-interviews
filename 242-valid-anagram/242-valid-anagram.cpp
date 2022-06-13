class Solution {
public:
    bool isAnagram(string s, string t) {
        //since s and t contains lowercase chars, we can keep a cntr array of size 26;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        int n=s.size(); 
        if(t.size()!=n) return 0;
        
        for(int i=0; i<n; i++){ 
            cnt1[s[i]-'a']++;
            cnt2[t[i]-'a']++;
        }
        
        if(cnt1==cnt2) return 1;
        return 0;
    }
};