class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int k){
        int n=piles.size(), curr=0;
        for(int i=0; i<n; i++){
            curr+=piles[i]/k; //hrs needed to eat piles[i] bananas, if she eats k in an hour; 
            if(piles[i]%k) curr++;
            if(curr>h) return 0;
        }
        return 1;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size(), lo=1, hi=*max_element(piles.begin(), piles.end()); 
        //max bananas coco can eat in an hour is the max number of bananas in a pile;
        if(h==n){ //since koko has n hours, she'll eat one pile in one hour, so it will be hi;
            return hi;
        }
        //she has more than n hours, so she can do better;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(isPossible(piles, h, mid)){ //this is possible, so check for even better;
                hi=mid;
            }
            else{ //she needs to up her eating game;
                lo=mid+1;
            }
        }
        return hi;
    }
};