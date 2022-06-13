class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(auto s: strs){
            string tmp=s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }
        vector<vector<string>> sol;
        for(auto i=hash.begin(); i!=hash.end(); i++){
            sol.push_back(i->second);
        }
        return sol;
    }
};