bool bs(vector<int> &v, int &k){
    int l=0, r=v.size()-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(k==v[mid]){
            return true;
        }
        else if(k>v[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return false;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int k) {
        vector<int> v;
        int n=mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<mat[i].size(); j++){
                v.push_back(mat[i][j]);
            }
        }
        return bs(v, k);
    }
};