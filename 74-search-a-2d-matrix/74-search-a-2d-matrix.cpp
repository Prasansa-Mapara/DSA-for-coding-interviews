class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int r=mat.size(), c=mat[0].size();
        int rstart=0, rend=r-1;
        int rmid, rind=-1;
        
        while(rstart<=rend){
            rmid=rstart+(rend-rstart)/2;
            
            if(target<mat[rmid][0]){
                rend=rmid-1;
            }
            else if(target>mat[rmid][c-1]){
                rstart=rmid+1;
            }
            else if(target>=mat[rmid][0] && target<=mat[rmid][c-1]){
                rind=rmid;
                break;
            }
            else{
                return false;
            }
        }
        
        if(rind!=-1){
            int cstart=0, cend=c-1;
            while(cstart<=cend){
                int cmid=cstart+(cend-cstart)/2;
                if(target==mat[rind][cmid]){
                    return true;
                }
                else if(target>mat[rind][cmid]){
                    cstart=cmid+1;
                }
                else{
                    cend=cmid-1;
                }
            }
        }
        return false;
    }
};