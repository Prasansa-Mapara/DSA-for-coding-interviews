#define all(x) x.begin(), x.end()
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        int n=a.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({a[i], i});
        }
        sort(all(v));
        int i=0, j=n-1;
        while(i<j){
            int sum=v[i].first+v[j].first;
            if(sum==k){
                return {v[i].second, v[j].second};
            }
            else if(sum>k){
                j--;
            }
            else{
                i++;
            }
        }
        return {};
    }
};