class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //we need to maintain elements in a descending order;
        //so front of queue will always have max;
        deque<int> q;
        vector<int> sol;
        int n=nums.size();
        for(int i=0; i<k; i++){
            while(q.size() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        sol.push_back(nums[q.front()]);
        for(int i=k; i<n; i++){
            while(q.size() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(i-q.front()+1>k) q.pop_front();
            sol.push_back(nums[q.front()]);
        }
        return sol;
    }
};