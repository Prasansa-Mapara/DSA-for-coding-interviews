class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(), start=0, cnt=0, sol=0;
        queue<int> q;
        for(int end=0; end<n; end++){
            if(!nums[end]){
                cnt++;
                q.push(end);
            }
            if(cnt>k){
                while(start>q.front()){
                    q.pop();
                }
                start=q.front()+1; 
                q.pop();
                cnt--;
            }
            sol=max(sol, end-start+1);
        }
        return sol;
    }
};