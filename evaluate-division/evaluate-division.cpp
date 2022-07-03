#define ff first
#define ss second

class Solution {
public:
    unordered_map<string, set<pair<string, double>>> adj;
     unordered_set<string> hash;
    double num;
    
    void dfs(string curr, string dst, unordered_map<string, bool> vis, double tmp){
        if(hash.find(curr)==hash.end()){
            return;
        }
        if(vis[curr]==1) return;
        vis[curr]=1;
        if(curr==dst){
            num=tmp;
            return;
        }
        for(auto i: adj[curr]){
            if(num!=-1) return;
            if(!vis[i.ff]){
                dfs(i.ff, dst, vis, tmp*i.ss);
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& eqn, vector<double>& val, vector<vector<string>>& queries) {
        //this is a graph problem, where each string's a node;
        //for traversal, we'll multiply edge weights;
       //dont even have to find shortest path, as no matter which path we go, 
        //final ans will be the same;
        //so, just have to find a path, if exists, then return ans, else return -1;
        
        int n=eqn.size();
        for(int i=0; i<n; i++){
            string a=eqn[i][0], b=eqn[i][1];
            double v=val[i];
            adj[a].insert({b, v});
            adj[b].insert({a, (double)1.0/v});
            hash.insert(a); hash.insert(b);            
        }
        vector<double> sol;
        for(auto q: queries){
            string src=q[0], dst=q[1];
            if(hash.find(dst)==hash.end()){
                sol.push_back((double)-1);
                continue;
            }
            unordered_map<string, bool> vis;
            double tmp=1;
            num=-1;
            dfs(src, dst, vis, tmp);
            sol.push_back(num);
        }
        
        return sol;
    }
};