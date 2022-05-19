class Solution {
public:
    string getHint(string sec, string gs) {
        int n=sec.size(), x=0, y=0;
        unordered_map<char, int> hash;
        for(auto c: gs){
            hash[c]++;
        }
        for(int i=0; i<n; i++){
            if(sec[i]==gs[i]){ //bulls;
                x++;
                hash[gs[i]]--;
            }
        }
        for(int i=0; i<n; i++){ //all bulls are calculated;
            if(sec[i]!=gs[i]){
                if(hash[sec[i]]>0){
                    y++; //cows;
                    hash[sec[i]]--;
                }
            }
        }
        string sol=to_string(x)+"A"+to_string(y)+"B";
        return sol;
    }
};