class SnapshotArray {
public:
    unordered_map<int, map<int, int>> hash; //index-->
    int s=0;
    
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        hash[index][s]=val;
    }
    
    int snap() {
        return s++;
    }
    
    int get(int index, int snap_id) {
        auto it=hash[index].upper_bound(snap_id);
        return it==begin(hash[index])?0: prev(it)->second;
    }
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */