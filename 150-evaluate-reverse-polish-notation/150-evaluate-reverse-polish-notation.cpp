class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for(auto c: tokens){
            if(c!="+" && c!="-" && c!="*" && c!="/"){
                st.push(stol(c));
            }
            else{
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                if(c=="+"){
                    st.push(a+b);
                }
                else if(c=="-"){
                    st.push(b-a);
                }
                else if(c=="*"){
                    st.push(a*b);
                }
                else{
                    st.push(b/a);
                }
            }
        }
        return st.top();
    }
};