class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int k) {
        int r=mat.size(), c=mat[0].size();
        int lo=0, hi=r-1, curr;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(k>=mat[mid][0] && k<=mat[mid][c-1]){
                curr=mid;
                break;
            }
            else if(k<mat[mid][0]){
                hi=mid-1;
            }
            else if(k>mat[mid][c-1]){
                lo=mid+1;
            }
        }
        lo=0, hi=c-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mat[curr][mid]==k){
                return true;
            }
            else if(mat[curr][mid]<k){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return false;
    }
};