class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a, b, cnt1=0, cnt2=0, n=nums.size();
        for(int i=0; i<n; i++){
            if(cnt1 && nums[i]==a){
                cnt1++;
            }
            else if(cnt2 && nums[i]==b){
                cnt2++;
            }
            else if(cnt1==0){
                a=nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                b=nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==a) cnt1++;
            else if(nums[i]==b) cnt2++;
        }
        vector<int> sol;
        if(cnt1>(n/3)) sol.push_back(a);
        if(cnt2>(n/3)) sol.push_back(b);
        return sol;
    }
};