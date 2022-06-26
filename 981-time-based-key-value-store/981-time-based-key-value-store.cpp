class TimeMap {
public:
    map<string, vector<pair<int, string>>> hash;
    
    TimeMap() {
        
    }
    
    void set(string key, string val, int time) {
        hash[key].push_back({time, val});
    }
    
    string get(string key, int time) {
        if(hash[key].size()==0) return "";
        int l=0, r=hash[key].size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(hash[key][mid].first==time){
                return hash[key][mid].second;
            }
            else if(hash[key][mid].first<time){
                if(mid+1<hash[key].size() && hash[key][mid+1].first<=time){
                    l=mid+1;
                }
                else{
                    return hash[key][mid].second;
                }
            }
            else{
                r=mid-1;
            }
        }
        if(hash[key][l].first<=time){
            return hash[key][l].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
