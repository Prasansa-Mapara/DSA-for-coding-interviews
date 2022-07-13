class Solution {
public:
    vector<int> partitionLabels(string s) {
        //since s is a lowercase string, we can store the last occurence 
        //for every letter in a vector;
        vector<int> last(26), sol;
        int n=s.size();
        for(int i=0; i<n; i++){
            last[s[i]-'a']=i;
        }
        int st=0, j=0;
        for(int ed=0; ed<n; ed++){
            j=max(j, last[s[ed]-'a']);
            if(j==ed){
                sol.push_back(ed-st+1);
                st=ed+1;
            }
        }
        return sol;
    }
};