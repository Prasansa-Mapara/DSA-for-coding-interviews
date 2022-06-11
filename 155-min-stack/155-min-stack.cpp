class MinStack {
public:
    map<int, int> hash;
    stack<int> s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        hash[val]++;
    }
    
    void pop() {
        int val=s.top();
        hash[val]--;
        if(hash[val]==0){
            hash.erase(hash.find(val));
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
         return hash.begin()->first;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */