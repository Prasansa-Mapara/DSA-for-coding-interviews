class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute force is sorting
        //for O(n) time, best approach is to union find;
        //check for curr-1, curr+1, then do set union;
        //implement this using a set;
        
        unordered_set<int> hash;
        for(auto i:nums){
            hash.insert(i);
        }
        if(hash.empty()) return 0;
        int sol=1;
        for(auto i:nums){
            if(hash.find(i-1)!=hash.end()){
                continue;
            }
            //i is the first num of the sequence;
            int tmp=1, curr=i+1;
            while(hash.find(curr)!=hash.end()){
                tmp++;
                curr++;
            }
            sol=max(sol, tmp);
        }
        return sol;
    }
};