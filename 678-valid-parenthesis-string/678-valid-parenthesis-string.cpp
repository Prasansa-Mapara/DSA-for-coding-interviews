class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int lMin=0, lMax=0;
        for(auto c: s){
            if(c=='('){
                lMin++; lMax++;
            }
            else if(c==')'){
                lMin--; lMax--;
            }
            else{ //since it's a star, i've 2 choices;
                lMax++; //cuz max me plus hi hoga;
                lMin--; //n min me - hi hoga;
            }
            //since, we have included, all possible * to left's in
            //lMax, and if its still negative, then answer's definitely not possible;
            if(lMax<0) return 0;
            //we have converted all *'s to rights in lMin, so 
            //its not working, so we can balance it out by making 0;
            if(lMin<0) lMin=0;
            //its safe to assign 0 to it, since, at any point, if stars kam hai, fir bhi this 
            //eqn not working, then lMax should also have been negative;
        }
        return lMin==0; //cuz the string is balanced if cnt of left parenthesis is 0;
    }
};