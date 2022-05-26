class Solution {
public:    
    void merge(vector<int> &a, int left, int right, long long int &sol){
        int mid=left+(right-left)/2;
        int i=left, j=mid+1;
        long long int cnt=0;
        while(i<=mid && j<=right){
            if(a[i]>((long long int)2*a[j])){
                cnt+=mid-i+1; //cuz all elements after and including i will all be gretaer than twice of a[j],
                //since both subarrays are sorted :))
                j++;
            }
            else{
                i++; //check if number greater than this would be greater, also, its safe to increment i as 
                //no number after j will give the require result, again cuz already sorted!
            }
        }
        i=left, j=mid+1;
        vector<int> tmp;
        while(i<=mid && j<=right){
            if(a[i]<=a[j]){
                tmp.push_back(a[i]);
                i++;
            }
            else{
                tmp.push_back(a[j]);
                j++;
            }
        }
        while(i<=mid){
            tmp.push_back(a[i++]);
        }
        while(j<=right){
            tmp.push_back(a[j++]);
        }
        j=0;
        for(int i=left; i<=right; i++){
            a[i]=tmp[j++];
        }
        sol+=cnt;
    }
    
    void mergeSort(vector<int> &nums, int left, int right, long long int &sol){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(nums, left, mid, sol);
        mergeSort(nums, mid+1, right, sol);
        merge(nums, left, right, sol);
    }
    
    int reversePairs(vector<int>& nums) {
        //STUFF LIKE COUNT INVERSIONS, REVERSE PAIRS IS DONE USING MERGE SORT; 
        //TIME COMPLEXITY WILL BE NLOGN, SO N WOULD BE IN RANGE OF 10^5 OR LESS, BUT NOT MORE (USUALLY);
        int n=nums.size(), l=0, r=n-1;
        long long int sol=0;
        mergeSort(nums, l, r, sol);
        return sol;
    }
};