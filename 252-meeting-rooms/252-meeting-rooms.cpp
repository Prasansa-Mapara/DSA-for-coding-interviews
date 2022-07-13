class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& time) {
        int n=time.size();
        sort(time.begin(), time.end());
        for(int i=1; i<n; i++){
            if(time[i][0]>=time[i-1][1]){
                time[i][1]=max(time[i][1], time[i-1][1]);
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};