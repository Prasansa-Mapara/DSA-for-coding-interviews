class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0, sol=-1, n=nums.size();
        for(auto i: nums){
            if(cnt==0){
                sol=i;
                cnt++;
            }
            else if(i==sol){
                cnt++;
            }
            else if(i!=sol){
                cnt--;
            }
        }
        cnt=0;
        for(auto i:nums){
            if(i==sol) cnt++;
        }
        if(cnt>(n/2)) return sol;
        else return -1;
    }
};