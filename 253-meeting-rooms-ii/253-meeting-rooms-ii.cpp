class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //[[13,15],[1,13]]
        //v=[{13,1},{15,0},{1,1},{13,0}]
        //v=[{1,1},{13,0},{13,1},{15,0}]
        int rooms=INT_MIN;
        stack<int> s;
        vector<pair<int, int>> v;
        for(int i=0; i<intervals.size(); i++){
            v.push_back({intervals[i][0], 1});
            v.push_back({intervals[i][1], 0});
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            if(v[i].second==1){
                s.push(1);
                rooms=max(rooms,(int)s.size());
            }
            else{
                if(!s.empty()){
                    s.pop();
                }
            }
        }
        return rooms;
    }
};