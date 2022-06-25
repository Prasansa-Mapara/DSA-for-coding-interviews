class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        //since we want to keep a decreasing order, can also try stack
        //not using deque, cuz we'll never be accessing the front element;
        stack<int> st;
        int n=temp.size();
        vector<int> sol(n, 0);
        for(int i=0; i<n; i++){
            while(st.size() && temp[i]>temp[st.top()]){
                int prev=st.top(); //cuz now the prev temp ghas found a hotter temp :)
                st.pop();
                sol[prev]=i-prev;
            }
            st.push(i);
        }
        return sol;
    }
};