class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<string>> hash(26);
        int sol=0;
        for(auto wrd: words){
            int i=wrd[0]-'a';
            hash[i].push_back(wrd);
        }
        for(auto ch: s){
            int i=ch-'a', n=hash[i].size();
            while(n--){
                string wrd=hash[i][0];
                hash[i].erase(hash[i].begin());
                wrd.erase(wrd.begin()); //remove first char
                if(wrd=="") sol++;
                else hash[wrd[0]-'a'].push_back(wrd);
            }
        }
        return sol;
    }
};