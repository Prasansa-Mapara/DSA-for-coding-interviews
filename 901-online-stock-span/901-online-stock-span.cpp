class StockSpanner {
public:
    stack<pair<int, int>> st;\
        
    StockSpanner() {
        
    }
    
    int next(int price) {
        int sol=1;
        while(st.size() && price>=st.top().first){
            sol+=st.top().second; //cuz prev price was less than or equal to curr price;
            st.pop();
        } 
        st.push({price, sol});
        return sol;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */