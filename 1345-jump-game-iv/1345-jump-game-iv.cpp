class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> hash;
        int n=arr.size();
        for(int i=0; i<n; i++){
            hash[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<bool> vis(n, 0);

        q.push(0);
        vis[0]=1;
        int steps=0;
        
        while(q.size()){
            int sz=q.size();
            
            while(sz--){
                int curInd=q.front();
                q.pop();
                
                if(curInd==n-1) return steps;
                
                vector<int> &nextIndices=hash[arr[curInd]]; //all indices that have the same value;
                nextIndices.push_back(curInd-1); //left index;
                nextIndices.push_back(curInd+1); //right index;
                
                for(auto ind: nextIndices){
                    if(ind>=0 && ind<n && !vis[ind]){
                        vis[ind]=1;
                        q.push(ind);
                    }
                }
                
                nextIndices.clear();
            }
            
            steps++;
        }
        
        return -1;
    }
};