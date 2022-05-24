class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(), sol=0, tmp=0;
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    sol=max(sol, i-st.top());
                }
            }
        }
        return sol;
    }
};