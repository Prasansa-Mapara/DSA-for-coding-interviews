class Solution {
public:
    //brute force code:
    
    /*long long maxPoints(vector<vector<int>>& pts) {
        int m=pts.size(), n=pts[0].size();
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int x=INT_MIN;
                for(int k=0; k<n; k++){
                    x=max(x, pts[i-1][k]-abs(k-j));
                }
                pts[i][j]+=x;
            }
        }
        return *max_element(pts[m-1].begin(), pts[m-1].end());
    }*/
    
    //optimized code:
    
    long long maxPoints(vector<vector<int>>& points) {
        int r=points.size(), c=points[0].size();
        vector<vector<long long>> pts(r, vector<long long> (c));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                pts[i][j]=(long long) points[i][j];
            }
        }
        //at any particular pt, max will either be directly on its top, or on the left side,
        //or on the right side;
        //i'll do it one after the other;
        
        
        vector<long long int> left(c, 0), right(c, 0);
        left[0]=pts[0][0];
        for(int j=1; j<c; j++){
            left[j]=max(left[j-1]-1, pts[0][j]); //cuz prev value will be reduced by 1 in each iteration;
        }
        right[c-1]=pts[0][c-1];
        for(int j=c-2; j>=0; j--){
            right[j]=max(right[j+1]-1, pts[0][j]);
        }
        for(int i=1; i<r; i++){
            for(int j=0; j<c; j++){
                pts[i][j]+=max(left[j], right[j]);
            }
            left[0]=pts[i][0]; right[c-1]=pts[i][c-1];
            for(int j=1; j<c; j++){
                left[j]=max(left[j-1]-1, pts[i][j]); //cuz prev value will be reduced by 1 in each iteration;
            }
            for(int j=c-2; j>=0; j--){
                right[j]=max(right[j+1]-1, pts[i][j]);
            }
        }
        return *max_element(pts[r-1].begin(), pts[r-1].end());
    }
};