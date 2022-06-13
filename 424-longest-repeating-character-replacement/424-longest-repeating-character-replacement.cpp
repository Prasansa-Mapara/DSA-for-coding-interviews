class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r, n=s.size(), cnt=0, sol=0;
        unordered_map<char, int> hash;
        
        for(int r=0; r<n; r++){
            hash[s[r]]++; //update frequency of curr element; 
            cnt=max(cnt, hash[s[r]]); //cnt will be the max frequency of an element in this window; 
            //we are not updating cnt with every iteration, cuz for sol to change, cnt will have to be increased;
            //so in case cnt remains the same, sol will also remain the same; 
            int x=(r-l+1)-cnt; //num of chars to replace in this window will be total window size- number of characters that appear most frequently; 
            if(x>k){
                hash[s[l]]--;
                l++; //length will have to decrease, so sol will remain same; 
            }
            sol=max(sol, r-l+1); //it is easy to observe that sol will change only when cnt is incremented; 
        }
        
        return sol;
    }
};