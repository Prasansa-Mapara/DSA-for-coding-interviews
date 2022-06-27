class LRUCache {
public:
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(hash.find(key)==hash.end()){
            return -1;
        }
        li.splice(li.begin(), li, hash[key]);
        hash[key]=li.begin();
        return hash[key]->second;
    }
    
    void put(int key, int val) {
        if(hash.find(key)==hash.end()){
            if(hash.size()>=cap){
                hash.erase(hash.find(li.back().first));
                li.pop_back();
            }
            li.push_front({key, val});
            hash[key]=li.begin();
        }
        else{
            li.splice(li.begin(), li, hash[key]);
            li.front().second=val;
            hash[key]=li.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */