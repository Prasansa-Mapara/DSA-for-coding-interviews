class MedianFinder {
public:
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
        int x=mxHp.size(), y=mnHp.size();
        if(x>(y+1)){
            mnHp.push(mxHp.top());
            mxHp.pop();
        }
        if(y>(x+1)){
            mxHp.push(mnHp.top());
            mnHp.pop();
        }
        return;
    }
    
    double findMedian() {
        if(mxHp.size()==mnHp.size()){
            return (double)(mnHp.top()+mxHp.top())/2.0;
        }
        else if(mxHp.size()>mnHp.size()){
            return (double)mxHp.top();
        }
        else{
            return (double)mnHp.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */