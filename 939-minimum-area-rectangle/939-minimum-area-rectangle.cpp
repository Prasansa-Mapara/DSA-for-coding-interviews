class Solution {
public:
    int minAreaRect(vector<vector<int>>& pts) {
        int n=pts.size(), area=INT_MAX;
        //min 2+2 pts wid equal y coordinates;
        //min 2+2 pts wid equal x coordinates;
        //in these 4 pts, there should be equal x as well as y
        
        unordered_map<int, unordered_set<int>> hash;
        for(auto i: pts){
            hash[i[0]].insert(i[1]);
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(pts[i][0]!=pts[j][0] && pts[i][1]!=pts[j][1]){ //if a diagonal can be formed from these pts;
                    int x1=pts[i][0], x2=pts[j][0], y1=pts[i][1], y2=pts[j][1];
                    if(hash[x1].find(y2)!=hash[x1].end() && hash[x2].find(y1)!=hash[x2].end()){
                        //pts are (x1, y1), (x1, y2), (x2, y1), (x2, y2);
                        area=min(area, abs(y1-y2)*abs(x1-x2));
                    }
                }
            }
        }     
        if(area==INT_MAX) area=0;
        return area;
    }
};