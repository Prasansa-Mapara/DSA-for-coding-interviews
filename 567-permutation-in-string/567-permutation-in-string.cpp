class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26, 0), tmp(26, 0);
        int n=s1.size();
        for(auto c: s1){
            hash[c-'a']++;
        }
        if(s2.size()<n) return 0;
        for(int i=0; i<n; i++){
            tmp[s2[i]-'a']++;
        }
        if(hash==tmp) return 1;
        for(int i=n; i<s2.size(); i++){
            tmp[s2[i]-'a']++;
            tmp[s2[i-n]-'a']--;
            if(hash==tmp) return 1;
        }
        return 0;
    }
};