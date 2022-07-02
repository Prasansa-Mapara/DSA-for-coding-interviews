class Solution {
public:
    string sol;
    
    bool isCyclic(char curr, unordered_map<char, unordered_set<char>> &adj, vector<int> vis, vector<int> &chk){
        if(vis[curr-'a']){
            return 1;
        }
        if(chk[curr-'a']){
            return 0;
        }
        vis[curr-'a']=1;
        for(auto c: adj[curr]){
            if(!chk[c-'a'] && isCyclic(c, adj, vis, chk)){
                return 1;
            }
        }
        chk[curr-'a']=1;
        sol.push_back(curr);
        return 0;
    }
    
    string alienOrder(vector<string>& words) {
        //if you observe it, its a graph problem, tht too scheduling;
        //so post-order dfs will do :)
        //nodes are the letters;
        
        int n=words.size();
        unordered_map<char, unordered_set<char>> adj; //graph;
        //since mapping's repeated we using a set, so for that, we using a map;
        
        for(auto s: words){
            for(auto c: s){
                adj[c]={}; //some nodes might not be mapped to any, so we need to store all the chars;
            }
        }
        
        //now make the graph;
        for(int i=1; i<n; i++){
            string s=words[i-1], t=words[i];
            int sz=min(s.size(), t.size());
            bool fl=0;
            for(int j=0; j<sz; j++){
                if(s[j]!=t[j]){
                    adj[s[j]].insert(t[j]);
                    fl=1;
                    break;
                }
            }
            if(!fl){
                if(s.size()>t.size()){
                    return "";
                }
            }
        }
        
        //graph's ready;
        vector<int> vis(26, 0), chk(26, 0);
        for(auto i: adj){
            char c=i.first;
            if(!chk[c-'a'] && isCyclic(c, adj, vis, chk)){
                return "";
            }
        }
        
        return {sol.rbegin(), sol.rend()};
    }
};