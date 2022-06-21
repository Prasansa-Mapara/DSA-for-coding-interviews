class Solution {
public:
    bool canJump(vector<int>& nums) {
        //just keep a track of which index's the safest, if i wanna reach the end;
        int n=nums.size(), safe=n-1; //cuz last pos's the safest;
        for(int i=n-2; i>=0; i--){
            int jump=i+nums[i]; //max pos i can reach from this index;
            if(jump>=safe){ //if we can reach the safe index from here, then all we gotta do
                //is try reach this index next, cuz it'll be the min index;
                safe=i;
            }
        }
        return safe==0; //if it's safe to reach end from first pos;
    }
};