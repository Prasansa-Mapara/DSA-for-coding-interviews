class Solution {
public:
    int uniqueLetterString(string s){
        int index[26][2], res=0, n=s.size(), mod=(1e9)+7;
        memset(index, -1, sizeof(int)*52);
        for (int i=0; i<n; ++i) {
            int c = s[i]-'A';
            res=(res+(i-index[c][1])*(index[c][1]-index[c][0])%mod)%mod;
            index[c][0]=index[c][1];
            index[c][1]=i;
        }
        for (int c=0;c<26;++c)
            res=(res+(n-index[c][1])*(index[c][1]-index[c][0])%mod)%mod;
        return res;
    }
};