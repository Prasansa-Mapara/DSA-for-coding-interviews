class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i=0;
    
    StockSpanner() {
        //we want previous prices to be less than or equal to current price;
        //so will maintain a monotonically decreasing stack and store indices in the stack;
        //so whenever there's an element greater than top of stack, will keep popping, 
        //till tht element is less than top of stack, then will update result;
    }
    
    int next(int price) {
        while(st.size() && price>=st.top().first){ //maintain a monotonically decreasing stack;
            st.pop();
        }
        int x=-1;
        if(st.size()){
            x=st.top().second;
        }
        st.push({price, i});
        i++;
        return i-x-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */