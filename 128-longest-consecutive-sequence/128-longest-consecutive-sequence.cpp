class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(), sol=0;
        unordered_set<int> hash;
        for(auto i: nums) hash.insert(i);
        for(int i=0; i<n; i++){
            if(hash.find(nums[i]-1)!=hash.end()){ //it is not the beginning of the sequence so don't do anything;
                
            }
            else{
                int x=nums[i], cnt=1;
                while(hash.find(x+1)!=hash.end()){ //this is the start of seq, so go till end;
                    cnt++; 
                    x++;
                }
                sol=max(sol, cnt);
            }
        }
        return sol;
    } 
};