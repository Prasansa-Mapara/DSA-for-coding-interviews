class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //one way is to use min heap, but that will be costly;
        //another way is to use quick selecty, but it will be O(n^2) in worst case;
        //so best way is to use bucket sort;
        
        unordered_map<int, int> hash;
        for(auto i: nums){
            hash[i]++;
        }
        //1->3, 2->2, 3->1
        //max frequency of any element will be n, so store these elements in a bucket(cntr array) 
        //and then iterate from the back;
        int n=nums.size();
        vector<vector<int>> buck(n+1);
        
        for(auto it=hash.begin(); it!=hash.end(); it++){
            buck[it->second].push_back(it->first);
        }
        
        vector<int> sol;
        
        //in worst case, this loop will go till O(nk);
        for(int i=n; i>0; i--){
            for(int j=0; j<buck[i].size(); j++){
                sol.push_back(buck[i][j]);
                if(sol.size()==k) return sol;
            }
        }
        
        return sol;
    }
};