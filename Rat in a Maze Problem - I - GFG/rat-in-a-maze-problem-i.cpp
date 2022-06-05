// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> sol;
    
    void dfs(vector<vector<int>> &mat, int x, int y, string tmp){
        int n=mat.size();
        if(x<0 || y<0 || x>=n || y>=n || !mat[x][y]) return;
        mat[x][y]=0; //mark node as visited;
        if(x==(n-1) && y==(n-1)){
            sol.push_back(tmp);
            mat[x][y]=1;
            return;
        }
        dfs(mat, x+1, y, tmp+"D");
        dfs(mat, x-1, y, tmp+"U");
        dfs(mat, x, y+1, tmp+"R");
        dfs(mat, x, y-1, tmp+"L");
        
        mat[x][y]=1;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string tmp="";
        dfs(m, 0, 0, tmp);
        return sol;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends