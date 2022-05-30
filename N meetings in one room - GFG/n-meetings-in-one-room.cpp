// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        //there's only 1 room, and we gotta find the maximum meetings we can 
        //manage in that one room;
        //so best is to keep selecting meetings that end quickly;
        //so sort according to end times;
        
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({end[i], start[i]});
        }
        sort(v.begin(), v.end());
        int curr=-1, meet=0;
        for(int i=0; i<n; i++){
            if(v[i].second>curr){ //start time of this meeting is greater than current end time
            //here curr is time when the latest meeting ended;
                meet++;
                curr=v[i].first; //update end time;
            }
        }
        return meet;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends