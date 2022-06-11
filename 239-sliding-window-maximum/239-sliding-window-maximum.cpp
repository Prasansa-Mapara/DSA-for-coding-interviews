class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;
        for(int i=0; i<k-1; i++){
            while(q.size() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> sol;
        for(int i=k-1; i<n; i++){
            while(q.size() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if((i-q.front()==k)) q.pop_front(); //size of sliding window is k;
            sol.push_back(nums[q.front()]);
        }
        return sol;
    }
};