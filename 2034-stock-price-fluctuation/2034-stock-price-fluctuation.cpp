#define pii pair<int, int>
#define ff first
#define ss second

class StockPrice {
public:
    int time=0;
    unordered_map<int, int> hash;
    priority_queue<pii, vector<pii>, greater<pii>> mnHp;
    priority_queue<pii> mxHp;
    
    StockPrice() {
        
    }
    
    void update(int ts, int price) { 
        //map;
        hash[ts]=price;
        time=max(time, ts);
        mnHp.push({price, ts});
        mxHp.push({price, ts});
    }
    
    int current() {
        //max heap by time;
        return hash[time];
    }
    
    int maximum() {
        //max heap by price;
        while(mxHp.size()){
            int p=mxHp.top().ff, t=mxHp.top().ss;
            if(hash[t]==p){
                return p;
            }
            else{
                mxHp.pop();
            }
        }
        return 0;
    }
    
    int minimum() {
        //min heap by price;
        while(mnHp.size()){
            int p=mnHp.top().ff, t=mnHp.top().ss;
            if(hash[t]==p){
                return p;
            }
            else{
                mnHp.pop();
            }
        } 
        return 0;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */