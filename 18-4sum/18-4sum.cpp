#define all(x) x.begin(), x.end()
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int k) {
        sort(all(a));
        vector<vector<int>> sol;
        set<vector<int>> hash;
        int n=a.size();
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int l=j+1, r=n-1;
                int sum=k-(a[i]+a[j]);
                while(l<r){
                    if(a[l]+a[r]==sum){
                        vector<int> tmp={a[i], a[j], a[l], a[r]};
                        if(hash.find(tmp)==hash.end()){
                            sol.push_back(tmp);
                            hash.insert(tmp);
                        }
                        l++;
                    }
                    else if((a[l]+a[r])<sum){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
            }
        }
        return sol;
    }
};