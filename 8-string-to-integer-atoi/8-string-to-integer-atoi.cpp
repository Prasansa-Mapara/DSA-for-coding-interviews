class Solution {
public:
    int myAtoi(string s) {
        //"4193 with words"
        int i=0, n=s.size();
        long long int num=0;
        bool neg=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && s[i]=='-') {neg=1; i++;}
        else if(i<n && s[i]=='+') i++;
        while(i<n && s[i]=='0'){
            i++;
        }
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                num=num*10 + s[i]-'0';
                if(!neg && num>pow(2, 31)-1){
                    return pow(2, 31)-1;
                }
                else if(neg && -num<-(pow(2, 31))){
                    return -(pow(2, 31));
                }
                i++;
            }
            else break;
        }
        if(neg){
            return -num;
        }
        else return num;
    }
};