class KthLargest {
public: 
    vector<int> v;
    int kk;
    
    KthLargest(int k, vector<int>& nums) {
        kk=k;
        v=nums;
        sort(v.begin(), v.end());
    }
    
    int add(int val) {
        int x=upper_bound(v.begin(), v.end(), val)-v.begin();
        v.insert(v.begin()+x, val);
        return v[v.size()-kk];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */