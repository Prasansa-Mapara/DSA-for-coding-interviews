class Solution {
public:
    string findReplaceString(string s, vector<int>& ind, vector<string>& src, vector<string>& tgt) {
        int n=src.size(), k=0;
        //replacements should occur parallely;
        for(int i=0; i<n; i++){
            if(s.substr(ind[i], src[i].size())==src[i]){
                s.erase(ind[i], src[i].size());
                if(ind[i]>=s.size()){
                    s+=tgt[i];
                }
                else s.insert(ind[i], tgt[i]);
                int k=tgt[i].size()-src[i].size(), tmp=ind[i];
                for(int j=i+1; j<n; j++){
                    if(ind[j]>=tmp) ind[j]+=k;
                }
            }
        }
        return s;
    }
};