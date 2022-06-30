class MedianFinder {
public:
    //since it's a median, it'll be (max(min elements)+min(max elements))/2;
    //so max heap will have smaller elements
    //and min heap will have greater elements;
    
    priority_queue<int> mxHp;
    priority_queue<int, vector<int>, greater<int>> mnHp;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxHp.empty() || num<=mxHp.top()){
            mxHp.push(num);
        }
        else{
            mnHp.push(num);
        }
        if(mxHp.size()>1+mnHp.size()){
            mnHp.push(mxHp.top());
            mxHp.pop();
        }
        else if(mnHp.size()>1+mxHp.size()){
            mxHp.push(mnHp.top());
            mnHp.pop();
        }
        return;
    }
    
    double findMedian() {
        if(mxHp.size()==mnHp.size()){
            return (double)(mxHp.top()+mnHp.top())/2.0;
        }
        if(mxHp.size()>mnHp.size()){
            return (double)mxHp.top();
        }
        return (double)mnHp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */