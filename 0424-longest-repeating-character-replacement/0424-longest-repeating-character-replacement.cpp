class Solution {
public:
    int characterReplacement(string s, int k) {
        /*int n=s.size();
        if(n<=1) return n;
        //we just need a sliding window;
        //we'll keep max freq of occurence, subtract it from len of sliding window;
        //if that value is less than or equal to k, we'll update our sol;
        //else, we'll just increment our left ptr;
        //here, we only have to update our freq when its greater than curr, cuz
        //otherwise, solution's anyway not gonna work;
        int l=0, r=0, sol=1;
        unordered_map<char, int> hash;
        int cnt=0; //max freq;
        for(r=0; r<n; r++){
            hash[s[r]]++;
            cnt=max(cnt, hash[s[r]]);
            int change=r-l+1-cnt;
            if(change<=k){
                sol=max(sol, r-l+1);
            }
            else{
                hash[s[l]]--;
                l++;
            }
        }
        return sol;*/
        
        
        
        int n=s.size(), l=0, r=0, f=0, sol=0;
        unordered_map<char, int> hash;
        
        while(r<n){
            hash[s[r]]++;
            if(hash[s[r]]>f){
                f=hash[s[r]];
            }
            int rep=r-l+1-f;
            if(rep<=k){
                sol=max(sol, r-l+1);
            }
            else{
                hash[s[l]]--;
                l++;
            }
            r++;
        }
        
        return sol;
    }
};