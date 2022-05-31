class Solution {
public:
    vector<vector<string>> sol;
    unordered_set<string> hash;
    
    bool isPal(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    
    void solve(string &s, int ind, vector<string> tmp){
        int n=s.size();
        if(ind>=n){
            sol.push_back(tmp);
            return;
        }
        for(int i=ind; i<n; i++){
            string curr=s.substr(ind, i-ind+1);
            if(hash.find(curr)==hash.end()){
                if(isPal(curr)){
                    hash.insert(curr);
                }
            }
            if(hash.find(curr)!=hash.end()){ //curr string's a palindrome;
                tmp.push_back(curr);
                solve(s, i+1, tmp);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        solve(s, 0, tmp);
        return sol;
    }
};