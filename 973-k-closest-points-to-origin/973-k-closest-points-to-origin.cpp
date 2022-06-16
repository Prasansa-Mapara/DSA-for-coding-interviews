bool cmp(vector<int> a, vector<int> b){
    return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        //can do using quick select; 
        //it has a cute stl implementation, so will use it :)
        
        nth_element(pts.begin(), pts.begin()+k, pts.end(), cmp); //here it will be one indexed, so with k its actually k-1;
        return vector<vector<int>> (pts.begin(), pts.begin()+k);
    }
};