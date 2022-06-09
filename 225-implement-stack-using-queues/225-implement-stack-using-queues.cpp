class MyStack {
public:
    queue<int> q1, q2;
    int topp;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        topp=x;
    }
    
    int pop() {
        int x;
        while(q1.size()){
            x=q1.front();
            q1.pop();
            if(q1.size()) q2.push(x);
        }
        while(q2.size()){
            topp=q2.front();
            q1.push(topp);
            q2.pop();
        }
        return x;
    }
    
    int top() {
        return topp;
    }
    
    bool empty() {
        if(q1.size()) return 0;
        return 1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */