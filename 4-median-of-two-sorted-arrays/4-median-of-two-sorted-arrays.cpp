class Solution {
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b){
        int na=a.size(), nb=b.size();
        if(nb<na) return findMedianSortedArrays(b, a);
    
        int total=na+nb;
        int half=(total+1)/2;
        int l=0, r=na;
    
        while(l<=r){
            int i=l+(r-l)/2;
            int j=half-i;
            
            int aleft=(i-1)>=0?a[i-1]: INT_MIN;
            int aright=(i<na)?a[i]: INT_MAX;
            int bleft=(j-1)>=0?b[j-1]: INT_MIN;
            int bright=(j<nb)?b[j]: INT_MAX;
    
            if(aleft<=bright && bleft<=aright){
                if(total%2){
                    return (double)max(aleft, bleft);
                }
                return (double)(max(aleft, bleft)+min(aright, bright))/2.0;
            }
            else if(aleft>bright) r=i-1;
            else l=i+1;
        }
    
        return 0.0;
    }

};