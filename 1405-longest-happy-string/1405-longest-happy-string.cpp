class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int n=a+b+c, cntA=0, cntB=0, cntC=0;
        string s;
        while(n--){
            if(a>=b && a>=c && cntA<2){
                s.push_back('a');
                a--; cntA++;
                cntB=0; cntC=0;
            }
            else if(b>=c && b>=a && cntB<2){
                s.push_back('b');
                b--; cntB++;
                cntA=0; cntC=0;
            }
            else if(c>=a && c>=b && cntC<2){
                s.push_back('c');
                c--; cntC++;
                cntA=0; cntB=0;
            }
            else{
                if(cntA==2){
                    if(cntB!=2 && b && b>=c){
                        s.push_back('b');
                        b--;
                        cntA=0; cntB++;
                    }
                    else if(cntC!=2 && c && c>=b){
                        s.push_back('c');
                        c--;
                        cntA=0; cntC++;
                    }
                }
                else if(cntB==2){
                    if(cntA!=2 && a && a>=c){
                        s.push_back('a');
                        a--;
                        cntB=0; cntA++;
                    }
                    else if(cntC!=2 && c && c>=a){
                        s.push_back('c');
                        c--;
                        cntB=0; cntC++;
                    }
                }
                else if(cntC==2){
                    if(cntB!=2 && b && b>=a){
                        s.push_back('b');
                        b--;
                        cntC=0; cntB++;
                    }
                    else if(cntA!=2 && a && a>=b){
                        s.push_back('a');
                        a--;
                        cntC=0; cntA++;
                    }
                }
            }
        }
        
        return s;
    }
};