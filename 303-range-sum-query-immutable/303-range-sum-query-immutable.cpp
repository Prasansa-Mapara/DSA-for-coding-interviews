class NumArray {
public:
    vector<int> v, pref;
    
    NumArray(vector<int>& nums) {
        v=nums;
        pref=nums;
        int n=nums.size();
        for(int i=1; i<n; i++){
            pref[i]+=pref[i-1];
        }
    }
    
    int sumRange(int l, int r) {
        return pref[r]-pref[l]+v[l];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */