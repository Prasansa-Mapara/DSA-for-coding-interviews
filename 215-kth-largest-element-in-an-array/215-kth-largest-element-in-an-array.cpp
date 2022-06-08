class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; //max heap;
        for(auto i:nums) pq.push(i);
        int sol;
        while(k--){
            sol=pq.top();
            pq.pop();
        }
        return sol;
    }
};