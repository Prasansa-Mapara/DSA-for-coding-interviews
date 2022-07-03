class Solution {
public:
    vector<vector<int>> sol;
    
    void dfs(vector<vector<int>> &adj, int curr, vector<int> tmp){
        int n=adj.size();
        if(curr==n-1){
            sol.push_back(tmp);
            return;
        }
        for(auto i: adj[curr]){
            tmp.push_back(i);
            dfs(adj, i, tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg        //adj is already given;
        int n=graph.size();
        //0->n-1;
        vector<int> tmp; tmp.push_back(0);
        dfs(graph, 0, tmp);
        return sol;
    }
};