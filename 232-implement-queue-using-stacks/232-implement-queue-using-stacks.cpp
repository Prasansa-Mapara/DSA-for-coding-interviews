class MyQueue {
public:
    int topp;
    stack<int> s1, s2;
    
    MyQueue() {
        
    }
    
    void push(int x) { //O(1)
        if(s1.empty()){
            topp=x;
        }
        s1.push(x);
    }
    
    int pop() {
        int n=s1.size();
        n--;
        while(n--){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s1.top();
        s1.pop();
        while(s2.size()){
            s1.push(s2.top());
            if(s1.size()==1) topp=s1.top();
            s2.pop();
        }
        return x;        
    }
    
    int peek() { //O(1)
        return topp;
    }
    
    bool empty() { //O(1)
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */