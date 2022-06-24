class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        if(n==1){
            return 1;
        }
        hash.insert(n);
        while(true){
            int tmp=n, x=0;
            while(tmp){
                int i=tmp%10;
                x+=i*i;
                tmp/=10;
            }
            if(hash.find(x)!=hash.end()){ //found this num before;
                return 0;
            }
            if(x==1) return 1;
            hash.insert(x);
            n=x;
        }
        return 0;
    }
};