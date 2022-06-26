class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0, r=arr.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[r]){ //min element on right side;
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return arr[r];
    }
};