class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        stack<int> s;
        int n=nums2.size();
        for(int i=0; i<n; i++){
            while(s.size() && nums2[i]>s.top()){
                hash[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(s.size()){
            hash[s.top()]=-1;
            s.pop();
        }
        n=nums1.size();
        vector<int> sol;
        for(int i=0; i<n; i++){
            sol.push_back(hash[nums1[i]]);
        }
        return sol;
    }
};