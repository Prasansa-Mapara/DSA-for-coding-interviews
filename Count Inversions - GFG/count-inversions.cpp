// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], int left, int right, long long int &inv){
        long long tmp[right-left+1];
        int mid=left+(right-left)/2, i=left, j=mid+1, k=0;
        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]){
                tmp[k++]=arr[i++];
            }
            else{
                inv+=mid-i+1;
                tmp[k++]=arr[j++];
            }
        }
        while(i<=mid){
            tmp[k++]=arr[i++];
        }
        while(j<=right){
            tmp[k++]=arr[j++];
        }
        //in only one case, left=0, right=n-1, else it can be anything else
        //keep this in mind while copying the array
        i=0, j=left;
        while(j<=right){
            arr[j++]=tmp[i++];
        }
        return;
    }
    
    void mergeSort(long long arr[], int left, int right, long long int &inv){
        if(left>=right){
            return;
        }
        int mid=left+(right-left)/2;  
        mergeSort(arr, left, mid, inv);
        mergeSort(arr, mid+1, right, inv);
        merge(arr, left, right, inv);
        return;
    }
    
    long long int inversionCount(long long arr[], long long n){
        int left=0, right=n-1;
        long long int inv=0;
        mergeSort(arr, left, right, inv);
        return inv;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends