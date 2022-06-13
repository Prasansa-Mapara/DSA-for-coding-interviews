class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(')');
            else if(s[i]=='{') st.push('}');
            else if(s[i]=='[') st.push(']');
            else{
                if(st.size() && s[i]==st.top()) st.pop();
                else return 0;
            }
        }
        if(st.size()) return 0;
        return 1;
    }
};