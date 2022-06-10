class LRUCache {
public:
    int cap;
    list<pair<int, int>> cache; //key-value;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(hash.find(key)==hash.end()){ //key not present;
            return -1;
        }
        else{ //since key is present, it will be moved to the front;
            cache.splice(cache.begin(), cache, hash[key]);
            hash[key]=cache.begin();
            return hash[key]->second;
        }
    }
    
    void put(int key, int value) {
        if(hash.find(key)==hash.end()){ //key not present;
            if(hash.size()>=cap){
                hash.erase(hash.find(cache.back().first));
                cache.pop_back(); //remove the least freuently used item;
            } 
            cache.push_front({key, value});
        }
        else{
            cache.splice(cache.begin(), cache, hash[key]);
            cache.front().second=value;
        }
        hash[key]=cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */