class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=nums[0], fast=nums[nums[0]];
        while(slow!=fast){ //detecting a cycle
            //cycle for sure exists because of the pigeonhole principle
            //(n+1 pigeons, n values;)
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        //now that we have a cycle, we want the starting pt of the cycle, because more than 
        //one element pts there;
        slow=0; 
        while(slow!=fast){ //algo to fidn starting pt of cycle;
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};