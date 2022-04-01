class Solution {
public:
    void reverseString(vector<char>& s) {
        //i will use 2 ptrs for this.
        int n=s.size();
        int i=0, j=n-1;
        while(i<j){
            swap(s[i], s[j]);{
                i++;
                j--;
            }
        }
        return;
    }
};