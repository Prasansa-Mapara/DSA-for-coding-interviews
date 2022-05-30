class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& time) {
        vector<pair<int, int>> v;
        int n=time.size();
        for(int i=0; i<n; i++){
            v.push_back({time[i][0], 1});
            v.push_back({time[i][1], 0});
        }
        sort(v.begin(), v.end());
        int  rooms=0, curr=0;
        n=v.size();
        for(int i=0; i<n; i++){
            if(v[i].second==1) curr++;
            else curr--;
            rooms=max(rooms, curr);
        }
        return rooms;
    }
};