class Solution {
public:
    vector<long long> maximumEvenSplit(long long sum) {
        if(sum%2) return {};
        vector<long long > v;
        long long curr=2;
        while(true){
            if(sum>=curr){
                sum-=curr;
                v.push_back(curr);
                curr+=2;
            }
            else{
                break;
            }
        }
        v[v.size()-1]+=sum;
        return v;
    }
};