class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), m=t.size();
        if(n<m) return "";
        unordered_map<char, int> hash, freq;
        for(auto i: t) freq[i]++;
        int st=0, ed=0, sz=n+1, ind=-1, cnt =0;
        
        while(ed<n){
            hash[s[ed]]++;
            if(hash[s[ed]]<=freq[s[ed]]){
                cnt++;
            }
            if(cnt==m){
                while(hash[s[st]]>freq[s[st]]){
                    hash[s[st]]--;
                    st++;
                }
                if(ed-st+1<sz){
                    sz=ed-st+1;
                    ind=st;
                }
            }
            ed++;
        }
        
        return ind==-1?"":s.substr(ind, sz);
    }
};