class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(), m=t.length();
        if(n<m) return "";
        int len=n+1, sInd=-1, j=0, cnt=0;
        unordered_map<char, int> hash, freq;
        for(auto c: t) freq[c]++;
        for(int i=0; i<n; i++){
            hash[s[i]]++;
            if(hash[s[i]]<=freq[s[i]]){ //this char is present in t,
                //and it isnt been calculated yet, so do this;
                cnt++;
            }
            if(cnt==m){
                while(hash[s[j]]>freq[s[j]]){
                    hash[s[j]]--;
                    j++;
                }
                if(i-j+1<len){
                    len=i-j+1;
                    sInd=j;
                }
            }
        }
        if(sInd==-1) return "";
        return s.substr(sInd, len);
    }
};