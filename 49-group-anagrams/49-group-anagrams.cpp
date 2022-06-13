class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //this approach ill take O(NKlogK);
       /* unordered_map<string, vector<string>> hash;
        for(auto s: strs){
            string tmp=s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }
        vector<vector<string>> sol;
        for(auto i=hash.begin(); i!=hash.end(); i++){
            sol.push_back(i->second);
        }
        return sol;*/
        
        //we can still get a better solution, if we store a cntr array instead of this;
        //O(NK);
        
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> sol;
        
        for(auto s: strs){
            vector<int> cntr(26, 0);
            for(auto c: s){
                cntr[c-'a']++;
            }
            string tmp;
            for(int i=0; i<26; i++){
                tmp+=to_string(cntr[i])+"#";
            }
            hash[tmp].push_back(s);
        }
        
        for(auto it=hash.begin(); it!=hash.end(); it++){
            sol.push_back(it->second);
        }
        
        return sol;
    }
};