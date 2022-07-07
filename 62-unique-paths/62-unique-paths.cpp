class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1), curr=prev;
        for(int i=1; i<m; i++){
            curr=prev;
            for(int j=1; j<n; j++){
                curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return curr[n-1];
    }
};