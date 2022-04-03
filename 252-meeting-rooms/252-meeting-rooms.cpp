class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<pair<int, int>> time;
        for(auto i: intervals){
            time.push_back({i[0], 1});
            time.push_back({i[1], 0});
        }
        sort(time.begin(), time.end());
        int cnt=0;
        for(auto i: time){
            if(i.second==1) cnt++;
            else cnt--;
            if(cnt>1) return 0;
        }
        return 1;
    }
};