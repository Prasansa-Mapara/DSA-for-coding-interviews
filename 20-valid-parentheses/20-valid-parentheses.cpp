class Solution {
public:
    bool isValid(string s) {
        stack<char> stacc;
        for(auto i: s){
            if(i=='(' || i=='{' || i=='['){
                stacc.push(i);
            }
            else{
                if(stacc.size()){
                    char y=i, x=stacc.top();
                    if((x=='(' && y==')')||(x=='{' && y=='}') || (x=='[' && y==']')){
                        stacc.pop();
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
        }
        if(stacc.empty()){
            return 1;
        }
        return 0;
    }
};