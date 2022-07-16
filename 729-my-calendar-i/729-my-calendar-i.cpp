class MyCalendar {
public:
    map<int, int> cal; //end-start
    //so sorting based on the end values;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next=cal.upper_bound(start); 
        //next meet ends after current meet starts;
        if(next!=cal.end() && next->second<end){ //if there is a valid next meeting, it should start after current meet ends;
            return 0;
        }
        cal[end]=start;
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */