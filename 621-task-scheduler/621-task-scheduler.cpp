class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        int sol=0, sz=tasks.size();
        for(auto c: tasks) hash[c]++;
        int freqMax=1;//to compute the number of empty cells;
        for(auto i: hash) freqMax=max(freqMax, i.second);
        int charMax=0;
        for(auto i: hash){
            if(i.second==freqMax){
                charMax++; //all the characters that have maximum frequency;
            }
        }
        sol+=(freqMax-1)*(1+n)+charMax;
        return max(sol, sz);
    }
};

//A,_,_,A,_,_,A;