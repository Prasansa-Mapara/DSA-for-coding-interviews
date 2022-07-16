class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int na=a.size(), nb=b.size();
        if(nb<na) return findMedianSortedArrays(b, a); //cuz we want a to be smaller;
        
        
        int total=na+nb; //size of final array;
        int half=(total+1)/2;
        
        //we are doing binary search on the smaller array;        
        int l=0, r=na;
        
        while(l<=r){
            //i will pt to mid of a, and j will point to mid of b;
            int i=l+(r-l)/2;
            int j=half-i; //cuz of 0-based indexing;
            int aleft=(i-1<0)?INT_MIN:a[i-1];
            int aright=(i>=na)?INT_MAX:a[i];
            int bleft=(j-1<0)?INT_MIN:b[j-1];
            int bright=(j>=nb)?INT_MAX:b[j];
            
            //now we are checking if my partitions are correct;
            if(aleft<=bright && bleft<=aright){
                if(total%2){ 
                    return (double)max(aleft, bleft);
                }
                else{
                    return (double) (max(aleft, bleft)+min(aright, bright))/2.0;
                }
            }
            else if(aleft>bright){
                r=i-1;
            }
            else{
                l=i+1;
            }
        }
        
        return 0;
    }
};

//in given case, a=[2]
//b=[1,3]
//half in odd case means median will be after those many elements;
