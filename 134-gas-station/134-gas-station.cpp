class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), ind=0, rem=0, sum=0;
        for(int i=0; i<n; i++){
            sum+=gas[i]-cost[i];
            rem+=gas[i]-cost[i]; //rem gas if we travel to next station;
            if(rem<0){ //not possible to travel to next station
                ind=i+1; //so start travelling from next station;
                rem=0;
            }
        }
        return (sum<0?-1:ind);
    }
};