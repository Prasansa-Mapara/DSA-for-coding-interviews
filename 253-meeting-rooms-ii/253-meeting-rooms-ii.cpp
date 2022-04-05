class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        for(auto i: intervals){
            v.push_back({i[0], 1});
            v.push_back({i[1], 0});
        }
        sort(v.begin(), v.end());
        int rooms=0, cnt=0;
        for(int i=0; i<v.size(); i++){
            if(v[i].second==1) cnt++;
            else cnt--;
            rooms=max(cnt, rooms);
        }
        return rooms;
    }
};