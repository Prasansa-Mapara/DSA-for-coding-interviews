class Solution {
public:
    string s;
    vector<bool> chk;
    
    bool isCyc(unordered_map<char, unordered_set<char>> &hash, char curr, vector<bool> vis){
        if(vis[curr-'a']){
            return 1;
        }
        if(chk[curr-'a']){
            return 0;
        }
        vis[curr-'a']=1;
        
        for(auto c: hash[curr]){
            if(!chk[c-'a'] && isCyc(hash, c, vis)){
                return 1;
            }
        }
        chk[curr-'a']=1;
        s.push_back(curr);
        return 0;
    }
    
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> hash;
        
        for(auto s: words){
            for(auto c: s){
                hash[c]={};
            }
        }
        
        int n=words.size();
        for(int i=1; i<n; i++){
            string s1=words[i-1], s2=words[i];
            int sz=min(s1.size(), s2.size());
            bool flag=0;
            for(int j=0; j<sz; j++){
                if(s1[j]!=s2[j]){
                    flag=1;
                    hash[s1[j]].insert(s2[j]);
                    break;
                }
            }
            if(!flag){
                if(s1.size()>s2.size()){
                    return "";
                }
            }
        }
        
        vector<bool> vis(26, 0);
        chk=vis;
        
        for(auto i: hash){
            char c=i.first;
            if(!chk[c-'a'] && isCyc(hash, c, vis)){
                return "";
            }
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};