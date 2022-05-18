class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        //first we need to make a graph; ing.pb(rec)
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indeg;
        vector<string> sol;
        
        int n=ing.size();
        for(int i=0; i<n; i++){
            for(auto x: ing[i]){
                adj[x].push_back(rec[i]);
                indeg[rec[i]]++;
            }
        }
        
        queue<string> q;
        for(auto x: sup){
            if(indeg[x]==0){ //it is already there in the supply; so we can use it first
                q.push(x);
            }
        }
        
        while(q.size()){
            string curr=q.front();
            q.pop();
            for(auto recipe: adj[curr]){ //for each recipe that can be made using current ingredient
                indeg[recipe]--;
                if(indeg[recipe]==0){ //all ingredients for this recipe have been added
                    sol.push_back(recipe);
                    q.push(recipe);
                }
            }
        }
        
        return sol;
    }
};