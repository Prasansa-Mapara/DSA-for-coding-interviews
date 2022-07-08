class Solution {
    
public:
    bool removeOnes(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        
        for(int j=0; j<c; j++){
            if(mat[0][j]==1){
                //flip that column;
                for(int i=0; i<r; i++){
                    mat[i][j]=!mat[i][j];
                }
            }
        }
		
		for(int i=1; i<r; i++){
            int cnt=0;
            for(int j=0; j<c; j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            if(cnt!=0 && cnt!=c) return 0;
        }
        
        return 1;
    }
};