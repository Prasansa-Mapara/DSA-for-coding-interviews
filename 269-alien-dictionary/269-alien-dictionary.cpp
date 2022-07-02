class Solution {
public:
    string sol;
    
    bool isCyc(char curr, unordered_map<char, unordered_set<char>> &adj, vector<int> vis, vector<int> &chk){
        if(vis[curr-'a']){
            return 1;
        }
        if(chk[curr-'a']){
            return 0;
        }
        vis[curr-'a']=1;
        for(auto c: adj[curr]){
            if(!chk[c-'a'] && isCyc(c, adj, vis, chk)){
                return 1;
            }
        }
        chk[curr-'a']=1;
        sol.push_back(curr);
        return 0;
    }
    
    string alienOrder(vector<string>& words) {
        vector<int> chk(26, 0), vis(26, 0);
        //nodes will be letters of english alphabet;
        unordered_map<char, unordered_set<char>> adj;
        for(auto s: words){
            for(auto c: s){
                adj[c]={}; //initially insert all the characters to form a correct graph;
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
                    adj[s1[j]].insert(s2[j]); //only first letter should differ;
                    break;
                }
            }
            if(!flag){ //initial letters are the same
                if(s1.size()>s2.size()){
                    return {};
                }
            }
        }
        //now my graph's ready;
        
        for(auto i: adj){
            char c=i.first;
            if(!chk[c-'a'] && isCyc(c, adj, vis, chk)){
                return {};
            }
        }
        
        return {sol.rbegin(), sol.rend()};
    }
};