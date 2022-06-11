class MinStack {
public:
    stack<int> s, mt; 
    
    MinStack() {
        //we def need another stack to keep a tracker for minimum;
        //so while popping, it wont affect our minimum value if we're popping greater values; 
        //when we are popping a smaller value, we'll just pop it from min tracker also; 
    }
    
    void push(int val) {
        s.push(val);
        if((mt.size() && val<=mt.top()) || mt.empty()){
            mt.push(val);
        }
    }
    
    void pop() {
        if(s.top()==mt.top()){ //if its a min till now, then we gotta pop it;
            mt.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mt.top();
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