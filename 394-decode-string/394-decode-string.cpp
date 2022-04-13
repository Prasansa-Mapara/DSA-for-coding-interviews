class Solution {
public:
    string decodeString(string s) {
        string sol="";
        int n=s.size(), i=0, tmp;
        while(i<n){
            if(s[i]>='1' && s[i]<='9'){
                string num="";
                while(s[i]>='0' && s[i]<='9'){
                    num+=s[i];
                    i++;
                }
                tmp=stoi(num);
                int l=i, r=i; //l will pt to '['
                stack<int> st;
                st.push(1);
                r++;
                while(st.size()){
                    if(s[r]=='[') st.push(1);
                    else if(s[r]==']') st.pop();
                    if(st.size())r++;
                }     
                string y="";
                int j=l+1;
                while(j<r){
                    y+=s[j];
                    j++;
                }
                string rec=decodeString(y);
                while(tmp--){
                    sol+=rec;
                }
                i=r+1;
            }
            else{
                sol+=s[i];
                i++;
            }
        }
        return sol;
    }
};