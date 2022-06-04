// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isPossible(int curr, vector<int> col, int m, int k, bool mat[101][101]){
    int n=col.size();
    for(int j=0; j<curr; j++){
        if(mat[curr][j]){ //if connected;
            if(col[j]==k){ //if colors are same, i.e. adjacent nodes have same color
                return 0;
            }
        }
    }
    return 1;
}

bool solve(int curr, vector<int> col, int m, bool mat[101][101]){
    int n=col.size();
    if(curr>=n) return 1;
    for(int k=1; k<=m; k++){
        if(isPossible(curr, col, m, k, mat)){
            int tmp=col[curr];
            col[curr]=k;
            if(solve(curr+1, col, m, mat)){
                return 1;
            }
            else{
                col[curr]=tmp; //backtrack cuz not possible;
            }
        }
    }
    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> col(n, 1);
    return solve(0, col, m, graph);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends