bool cmp(vector<int> x, vector<int> y){
    return (x[0]*x[0]+x[1]*x[1])<(y[0]*y[0]+y[1]*y[1]);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        nth_element(pts.begin(), pts.begin()+k, pts.end(), cmp);
        return vector<vector<int>> (pts.begin(), pts.begin()+k);
    }
};