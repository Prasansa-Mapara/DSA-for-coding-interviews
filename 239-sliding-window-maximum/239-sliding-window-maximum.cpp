class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        //since numbers are not distinct, we'll store indices in the queue;
        //we'll maintain a decreasing order queue, so max will always be at head;
        vector<int> sol;
        deque<int> q;
        for(int i=0; i<n; i++){
            if(q.size() && (i-q.front())==k){
                q.pop_front(); //cuz size of sliding window is k, so remove previous elements;
            }
            while(q.size() && nums[q.back()]<nums[i]){
                q.pop_back(); //we want to maintain a descending order;
            }
            q.push_back(i);
            if((i-k+1)>=0){
                sol.push_back(nums[q.front()]);
            }
        }
        return sol;
    }
};