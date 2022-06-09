class MyStack {
public:
    queue<int> q;
    int topp;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topp=x;
    }
    
    int pop() {
        int n=q.size();
        n--;
        while(n--){
            topp=q.front();
            q.pop();
            q.push(topp);
        }
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return topp;
    }
    
    bool empty() {
        if(q.size()) return 0;
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