class Solution {
public:
    bool isPossible(vector<int> &piles, int k, int h){
        int n=piles.size(), curr=0; 
        if(k==0){
            return 0;
        }
        for(int i=0; i<n; i++){
            curr+=piles[i]/k;
            if(piles[i]%k) curr++; //curr=4
            if(curr>h) return 0;
        }
        if(curr>h) return 0;
        return 1;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int hi=0;
        for(auto i:piles){
            hi+=i;
        }
        //lo=0, hi=13
        long long int lo=0;
        while(lo<hi){
            long long int mid=lo+(hi-lo)/2; //13
            if(isPossible(piles, mid, h)){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return hi;
    }
};