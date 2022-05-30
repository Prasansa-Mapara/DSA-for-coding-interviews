class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int n=v.size();
        for(int i=1; i<n; i++){
            if(v[i][0]<v[i-1][1]){
                return false;
            }
        }
        return true;
    }
};