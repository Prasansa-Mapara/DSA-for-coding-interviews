class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(), req=n/2;
        unordered_map<int, int> hash;
        for(auto i: nums){
            hash[i]++;
            if(hash[i]>req){
                return i;
            }
        }
        return -1;
    }
};