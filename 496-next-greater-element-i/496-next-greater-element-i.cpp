class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        int n=nums2.size();
        for(int i=0; i<n; i++){
            int x=nums2[i];
            bool flag=0;
            for(int j=i+1; j<n; j++){
                int y=nums2[j];
                if(y>x){
                    flag=1;
                    hash[x]=y;
                    break;
                }
            }
            if(!flag){
                hash[x]=-1;
            }
        }
        vector<int> sol;
        n=nums1.size();
        for(int i=0; i<n; i++){
            sol.push_back(hash[nums1[i]]);
        }
        return sol;
    }
};